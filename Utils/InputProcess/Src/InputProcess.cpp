#include "InputProcess.h"
inputProcess::inputProcess() : running(false) {}

inputProcess::~inputProcess()
{
    stopInputThread();
}
inputProcess *inputProcess::getInstance()
{
    static std::shared_ptr<inputProcess> instance = std::make_shared<inputProcess>();
    return instance.get();
}

void inputProcess::setGlobalKey(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string inputProcess::getGlobalKey()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}

void inputProcess::setConnectMQTTResult(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string inputProcess::getConnectMQTTResult()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}

void inputProcess::setSendDataResult(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string inputProcess::getSendDataResult()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}
void inputProcess::setReSend(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string inputProcess::getReSend()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}
void inputProcess::startInputThread()
{
    running = true;
    mInputThread = std::thread([this]()
                               {
        while (running) {
        std::string key;
        if (std::getline(std::cin, key)) {
            std::lock_guard<std::mutex> lock(mMutex);
            if(key == "1") {
                mSendDataResult = "ok";
            } else if(key == "0") {
                mSendDataResult = "nok";
            } else if (key == "re") {
                mConnectMQTTResult = "ok";
            } else if (key == "nre") {
                mConnectMQTTResult = "nok";
            } else if(key=="res") {
                mReSend = "ok";
            } else {
                mGlobalKey = key;
            }
            if(mCallback){
                mCallback(key);
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } });
}
void inputProcess::stopInputThread()
{
    running = false;
}
void inputProcess::setCallBackInputProcess(std::function<void(const std::string&)>callBack){
    mCallback = callBack;
}