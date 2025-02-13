#include "AudioMgrSrv.h"

int main(int argc, char *argv[])
{
    printLog_I("Start AudioMgrSrv");
    defaultServiceManager()->addService(android::String16("AudioMgrSrv"), new AudioMgrSrv());
    android::ProcessState::self()->startThreadPool();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 1;
}