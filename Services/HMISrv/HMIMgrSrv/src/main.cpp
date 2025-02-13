#include <iostream>
#include "HMIMgrSrv.h"

int main(int argc, char *argv[])
{
    printLog_I("Start HMIMgrSrv");
    android::defaultServiceManager()->addService(android::String16("HMIMgrSrv"), new HMIMgrSrv());
    android::ProcessState::self()->startThreadPool();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 1;
}