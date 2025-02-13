#ifndef AUDIO_SRV_COMMAND_HANDLE
#define AUDIO_SRV_COMMAND_HANDLE
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>
#include <memory>
#include <binder/IServiceManager.h>
#include "ICommandHandler.h"
#include "IAudioServiceInterface.h"
#include "PlayAudio.h"
#include "ParameterDef.h"

#define playAudio std::string("playAudio")
#define stopAudio std::string("stopAudio")

class AudioMgrSrvCommandHandler : public ICommandHandler, public std::enable_shared_from_this<AudioMgrSrvCommandHandler>
{
private:    
    android::sp<AudioServiceInterface::IAudioServiceInterface> audio;
    android::sp<android::IBinder> binder;
    
public:
    std::string parseCommand(std::string strRawInput);
    CommandArg parseArg(std::string strRawInput);
    COMMAND_RESULT executeCommand(std::string strCommand, std::shared_ptr<CommandArg> arg);
    COMMAND_RESULT displayHelp();
    static COMMAND_RESULT PlayAudio(std::shared_ptr<AudioMgrSrvCommandHandler> self, std::shared_ptr<CommandArg> arg);
    static COMMAND_RESULT StopAudio(std::shared_ptr<AudioMgrSrvCommandHandler> self, std::shared_ptr<CommandArg> arg);
};

#endif /*AUDIO_SRV_COMMAND_HANDLE*/