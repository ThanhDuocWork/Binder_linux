#include "HMIMgrSrv.h"

::android::binder::Status HMIMgrSrv::requestLedPattern(const ::android::String16 &ledPattern)
{
    printLog_I("Request LED pattern: %s", toString(ledPattern).c_str());
    return ::android::binder::Status();
}


::android::binder::Status HMIMgrSrv::registerReceiver(const ::android::sp<::android::IBinder> &binder)
{
    android::sp<HMIReceiver::IHMIReceiver> receiver = android::interface_cast<HMIReceiver::IHMIReceiver>(binder);
    if (receiver != nullptr)
    {
        mReceiverList.push_back(receiver);
    }
    else
    {
        printLog_I("receiver is null");
    }
    return ::android::binder::Status::ok();
}
HMIMgrSrv::HMIMgrSrv(){
    startInputThread();
}
HMIMgrSrv::~HMIMgrSrv(){
    stopInputThread();
}   
void HMIMgrSrv::onHMIReceived(std::string data)
{
    if (!mReceiverList.empty())
    {
        android::sp<HMIReceiver::IHMIReceiver> obj{mReceiverList.front()};
        if (obj == nullptr)
        {
            printLog_I("obj is nullptr");
        }
        else
        {
            obj->onHMIReceived(android::String16(data.c_str()));
            printLog_I("obj->onHMIReceived(android::String16(data.c_str()));");
        }
    }
    if (data == "s")
    {
        printLog_I("data s HMIMgrSrv");
    }
}
////////////////////////////////////////////////////////
void HMIMgrSrv::setGlobalKey(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string HMIMgrSrv::getGlobalKey()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}

void HMIMgrSrv::setConnectMQTTResult(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string HMIMgrSrv::getConnectMQTTResult()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}

void HMIMgrSrv::setSendDataResult(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string HMIMgrSrv::getSendDataResult()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}
void HMIMgrSrv::setReSend(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mGlobalKey = key;
}

std::string HMIMgrSrv::getReSend()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mGlobalKey;
}
void HMIMgrSrv::startInputThread()
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
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } });
}
void HMIMgrSrv::stopInputThread()
{
    running = false;
}
