#include "CommanderHelper.h"
   
std::string CommanderHelper::strRaw(int argc, char *argv[])
{
    std::string str;
    for (int i = 0; i < argc; i++)
    {
        str += argv[i];
        if (i < argc)
        {
            str += " ";
        }
    }
    return str;
}

std::string CommanderHelper::parseService(std::string strInput)
{
    std::istringstream iss(strInput);
    std::vector<std::string> tokens;
    std::string token;
    std::string serviceStr;
    while (iss >> token)
    {
        tokens.push_back(token);
    }
    if (tokens.size() > 1)
    {
        serviceStr = tokens.at(1);
    }
    return serviceStr;
}

void CommanderHelper::showResult(const COMMAND_RESULT &result, const std::shared_ptr<CommandArg> arg,
                                 const std::string &Command, const std::shared_ptr<ICommandHandler> CommandHandle)
{
    if ((Command != playAudio && Command != stopAudio) || Command == "")
    {
        std::cout << "Unknow command: " << Command << std::endl;
        CommandHandle->displayHelp();
        return;
    }

    std::cout << "=============================" << std::endl;
    std::cout << "Command: " << Command << std::endl;
    switch (result)
    {
    case (COMMAND_RESULT::INVALID_INPUT_COMMAND):
    {
        std::cout << "Result: Invalid command " << std::endl;
        break;
    }
    case (COMMAND_RESULT::INVALID_INPUT_FILEPATH):
    {
        std::cout << "Result: File " << arg->mArg.at(0) << " not exist!" << std::endl;
        break;
    }
    case (COMMAND_RESULT::ERROR_INIT):
    {
        std::cout << "Result: Init Audio fail!" << std::endl;
        break;
    }
    case (COMMAND_RESULT::ERROR_OPEN_DEVICE):
    {
        std::cout << "Result: Can't open sound device!" << std::endl;
        break;
    }
    case (COMMAND_RESULT::ERROR_READ_FILE):
    {
        std::cout << "Result: Can't open " << arg->mArg.at(0) << " file!" << std::endl;
        break;
    }
    case (COMMAND_RESULT::OK):
    {
        std::cout << "Result: OK" << std::endl;
        break;
    }
    case (COMMAND_RESULT::UNKNOWN):
    {
        std::cout << "Result: UNKNOWN" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Result: " << std::endl;
        break;
    }
    }
    std::cout << "=============================" << std::endl;
}
