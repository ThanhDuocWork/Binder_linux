#ifndef HMI_MNG_SRV_H_
#define HMI_MNG_SRV_H_

#include <binder/BinderService.h>
#include <binder/IInterface.h>
#include <iostream>

#include <BnHMIServiceInterface.h>
#include <BpHMIServiceInterface.h>
#include <HMIReceiver/IHMIReceiver.h>
#include <IHMIServiceInterface.h>

#include <chrono>
#include <list>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include "Logger.h"
#include "Utils.h"
//#include "InputProcess.h"
class HMIMgrSrv : public HMIServiceInterface::BnHMIServiceInterface
{
    public:
    virtual ::android::binder::Status requestLedPattern (const ::android::String16 &ledPattern);
    virtual ::android::binder::Status registerReceiver (const ::android::sp<::android::IBinder> &binder);
    void onHMIReceived (std::string data);

    static HMIMgrSrv *getInstance ()
    {
        static android::sp<HMIMgrSrv> instance = new HMIMgrSrv();
        return instance.get();
    }
    // check input keyboard
    HMIMgrSrv();
    ~HMIMgrSrv();
    void setGlobalKey(const std::string &key);
    std::string getGlobalKey();
    void setSendDataResult(const std::string &key);
    std::string getSendDataResult();
    void setConnectMQTTResult(const std::string &key);
    std::string getConnectMQTTResult();
    void setReSend(const std::string &key);
    std::string getReSend();
    void startInputThread();
    void stopInputThread();     

    private:
    std::list<android::sp<HMIReceiver::IHMIReceiver>> mReceiverList;

    //check input keyboard
    std::string mGlobalKey;
    std::string mSendDataResult;
    std::string mConnectMQTTResult;
    std::string mReSend;
    std::mutex mMutex;
    bool running;     
    std::thread mInputThread;
};

#endif