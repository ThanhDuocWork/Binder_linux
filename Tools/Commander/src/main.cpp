#include <iostream>
#include <sstream>
#include <memory>
#include <cstdlib>
#include "MessageHandler.h"
#include "AudioAdapter.h"
#include "ICommandHandler.h"
#include "CommanderHelper.h"
#include "CommandService.h"

int main(int argc, char *argv[])
{
    CommanderHelper help;
    std::string str = help.strRaw(argc, argv);

    auto it = SERVICE_EXECUTE_TABLE.find(help.parseService(str));
    if (it != SERVICE_EXECUTE_TABLE.end())
    {
        std::string strCommand = it->second->parseCommand(str);
        std::shared_ptr<CommandArg> Arg = std::make_shared<CommandArg>(it->second->parseArg(str));
        COMMAND_RESULT result = it->second->executeCommand(strCommand, Arg);
        help.showResult(result, Arg, strCommand, it->second);
    }
    else
    {
        std::cout << "Unknow: " << help.parseService(str) << std::endl;
    }

    return 0;
}

