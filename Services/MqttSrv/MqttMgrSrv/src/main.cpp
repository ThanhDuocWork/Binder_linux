#include <iostream>
#include "MqttMgrSrv.h"

int main(int argc, char *argv[])
{
    printLog_I("Start MqttMgrSrv");
    android::defaultServiceManager()->addService(android::String16("MqttMgrSrv"), new MqttMgrSrv());
    android::ProcessState::self()->startThreadPool();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 1;
}