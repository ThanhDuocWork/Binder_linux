#ifndef I_COMMAND_HANDLER
#define I_COMMAND_HANDLER
#include <utils/String16.h>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

enum class COMMAND_RESULT : uint32_t
{
    OK = 0,
    NG,
    INVALID_INPUT_COMMAND,
    INVALID_INPUT_FILEPATH,
    INVALID_INPUT_ARG,
    ERROR_INIT,
    ERROR_OPEN_DEVICE,
    ERROR_OPEN_FILE,
    ERROR_READ_FILE,
    UNKNOWN
};

class CommandArg
{
public:
    std::vector<std::string> mArg;
    uint32_t mArg2;
    int flag;
};

class ICommandHandler
{
public:
    virtual std::string parseCommand(std::string strRawInput) = 0;
    virtual CommandArg parseArg(std::string strRawInput) = 0;
    virtual COMMAND_RESULT executeCommand(std::string strRawInput, std::shared_ptr<CommandArg> arg) = 0;
    virtual COMMAND_RESULT displayHelp() = 0;
    
};


#endif /*I_COMMAND_HANDLER*/