#ifndef HMI_ADAPTER_H
#define HMI_ADAPTER_H
#include "BnHMIReceiver.h"
#include "HMIServiceInterface/IHMIServiceInterface.h"
#include "IAdapter.h"
#include "MessageHandler.h"
#include "ParameterDef.h"
#include "ServiceDeathRecipient.h"
#include <binder/IInterface.h>
#include <memory.h>
namespace EmergencyCall
{
class HMIEventData : public EventData
{
    public:
    HMIEventData ()
    : mHMIData (""), EventData (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::HMI_EVENT_RECEIVED)){

      };
    HMIEventData (uint32_t messageId) : EventData (messageId)
    {
    }
    ~HMIEventData (){};

    const std::string getData ()
    {
        return mHMIData;
    }

    void setData (const std::string data)
    {
        mHMIData = data;
    }

    private:
    std::string mHMIData;
};


class HMIAdapter : public IAdapter
{
    class HMIReceiver : public ::HMIReceiver::BnHMIReceiver
    {
        public:
        HMIReceiver (HMIAdapter &hmiAdapter) : mParent (hmiAdapter)
        {
        }
        HMIReceiver ()  = delete;
        ~HMIReceiver () = default;
        android::binder::Status onHMIReceived (const android::String16 &data)
        {
            mParent.onHMIReceived (android::String8 (data).string ());
            return ::android::binder::Status ();
        };

        private:
        HMIAdapter &mParent;
    };

    public:
    ~HMIAdapter (){};
    HMIAdapter ();
    void registerService ();
    void requestLedPattern (std::string pattern);
    void onHMIReceived (std::string data);
    static HMIAdapter *getInstance ();
    void onBinderDied (const android::wp<android::IBinder> &who);

    private:
    android::sp<HMIServiceInterface::IHMIServiceInterface> mHMISrv;
    android::sp<HMIReceiver> receiver;
    android::sp<::android::IBinder> binder;
    android::sp<ServiceDeathRecipient> mServiceDeathRecipient;
};
} // namespace EmergencyCall
#endif /* HMI_ADAPTER_H */
