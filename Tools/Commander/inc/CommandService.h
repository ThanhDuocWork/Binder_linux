
#ifndef COMMAND_SERVICE
#define COMMAND_SERVICE
#include <map>
#include <iostream>
#include <memory>
#include "AudioMgrSrvCommandHandler.h"
static const std::map<std::string, std::shared_ptr<ICommandHandler>>
    SERVICE_EXECUTE_TABLE{  
        {"AudioMgrSrv", std::make_shared<AudioMgrSrvCommandHandler>()}   };
#endif /*COMMAND_SERVICE */
    