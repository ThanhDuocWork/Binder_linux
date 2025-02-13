#include "AudioMgrSrvCommandHandler.h"

using pairCommand = std::pair<std::function<COMMAND_RESULT(std::shared_ptr<AudioMgrSrvCommandHandler>, std::shared_ptr<CommandArg>)>, std::string>;
static const std::map<std::string, pairCommand> COMMAND_EXECUTE_TABLE =
    {
        {"playAudio", std::make_pair(AudioMgrSrvCommandHandler::PlayAudio, "Play the Audio file from input")},
        {"stopAudio", std::make_pair(AudioMgrSrvCommandHandler::StopAudio, "Stop the audio being played")}};

std::string AudioMgrSrvCommandHandler::parseCommand(std::string strRawInput)
{
    std::istringstream iss(strRawInput);
    std::vector<std::string> tokens;
    std::string token;
    std::string CommandStr = "";
    while (iss >> token)
    {
        tokens.push_back(token);
    }

    if (tokens.size() > 2)
    {
        CommandStr = tokens[2];
    }
    return CommandStr;
}

CommandArg AudioMgrSrvCommandHandler::parseArg(std::string strRawInput)
{
    CommandArg Arg;
    std::istringstream iss(strRawInput);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    for (size_t i = 3; i < tokens.size(); ++i)
    {
        Arg.mArg.push_back(tokens[i]);
    }
    return Arg;
}

COMMAND_RESULT AudioMgrSrvCommandHandler::executeCommand(std::string strCommand, std::shared_ptr<CommandArg> arg)
{
    binder = android::defaultServiceManager()->getService(android::String16(binder_service::BINDER_AUDIO_SERVICE_NAME));
    if (binder != 0)
    {
        audio = android::interface_cast<AudioServiceInterface::IAudioServiceInterface>(binder);
        auto it = COMMAND_EXECUTE_TABLE.find(strCommand);
        if (it != COMMAND_EXECUTE_TABLE.end())
        {
            if (arg->mArg.at(0) != std::string("help"))
            {
                return it->second.first(shared_from_this(), arg);
            }
            else
            {
                if (arg->mArg.at(0) == std::string("help"))
                {
                    std::cout << it->second.second << std::endl;
                    return COMMAND_RESULT::UNKNOWN;
                }
                else
                {
                    return COMMAND_RESULT::INVALID_INPUT_ARG;
                    displayHelp();
                }
            }
        }
        else
        {
            return COMMAND_RESULT::INVALID_INPUT_COMMAND;
            displayHelp();
        }
    }
}

COMMAND_RESULT AudioMgrSrvCommandHandler::StopAudio(std::shared_ptr<AudioMgrSrvCommandHandler> self, std::shared_ptr<CommandArg> arg)
{
    self->audio->StopAudio(&arg->flag);
    if (arg->flag == static_cast<int>(FLAG_AUDIO::OK))
    {
        return COMMAND_RESULT::OK;
    }
    return COMMAND_RESULT::UNKNOWN;
}

COMMAND_RESULT AudioMgrSrvCommandHandler::PlayAudio(std::shared_ptr<AudioMgrSrvCommandHandler> self, std::shared_ptr<CommandArg> arg)
{
    arg->flag = 0;
    std::ifstream file(arg->mArg.at(0));
    if (!file.good())
    {
        return COMMAND_RESULT::INVALID_INPUT_FILEPATH;
    }
    self->audio->PlayAudio(android::String16(arg->mArg.at(0).c_str()), &arg->flag);
    
    switch (static_cast<FLAG_AUDIO>(arg->flag))
    {
    case FLAG_AUDIO::ERROR_INIT:
    {
        return COMMAND_RESULT::ERROR_INIT;
    }
    case FLAG_AUDIO::ERROR_OPEN_DEVICE:
    {
        return COMMAND_RESULT::ERROR_OPEN_DEVICE;
    }
    case FLAG_AUDIO::ERROR_OPEN_FILE:
    {
        return COMMAND_RESULT::ERROR_OPEN_FILE;
    }
    case FLAG_AUDIO::ERROR_READ_FILE:
    {
        return COMMAND_RESULT::ERROR_READ_FILE;
    }
    case FLAG_AUDIO::OK:
    {
        return COMMAND_RESULT::OK;
    }
    default:
    {
        return COMMAND_RESULT::UNKNOWN;
    }
    }
}

COMMAND_RESULT AudioMgrSrvCommandHandler::displayHelp()
{
    std::cerr << "Usage: commander [APP_NAME/SERIVCE_NAME] [COMMAND_NAME] [ARG1] [ARG2] ..." << std::endl;
    std::cerr << "Options:" << std::endl;
    std::cerr << "   [APP_NAME/SERIVCE_NAME]    :   AudioMgrSrv" << std::endl;
    std::cerr << "   [COMMAND_NAME]             :   playAudio/stopAudio" << std::endl;
    std::cerr << "   [ARG1]                     :   <the file path of the audio>/help" << std::endl;
    return COMMAND_RESULT::OK;
}