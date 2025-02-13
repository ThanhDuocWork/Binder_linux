#ifndef COMMANDER_HEPLER
#define COMMANDER_HEPLER
#include <iostream>
#include <map>
#include "AudioMgrSrvCommandHandler.h"

class CommanderHelper
{
private:
public:
    std::string strRaw(int argc, char *argv[]);
    std::string parseService(std::string strInput);
    void showResult(const COMMAND_RESULT &result, const std::shared_ptr<CommandArg> arg,
                    const std::string &Command, const std::shared_ptr<ICommandHandler> CommandHandle);
};
    
#endif