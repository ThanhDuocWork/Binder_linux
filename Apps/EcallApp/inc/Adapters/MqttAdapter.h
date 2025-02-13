#ifndef MQTT_ADAPTER_H
#define MQTT_ADAPTER_H
#include "BnMqttReceiver.h"
#include "IAdapter.h"
#include "MessageHandler.h"
#include "MqttServiceInterface/IMqttServiceInterface.h"
#include "ParameterDef.h"
#include "ServiceDeathRecipient.h"
#include <binder/IInterface.h>
#include <memory.h>

namespace EmergencyCall
{
class MqttEventData : public EventData
{
    public:
    MqttEventData () : EventData (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::MQTT_EVENT_RECEIVED))
    {
    }

    MqttEventData (uint32_t messageId) : EventData (messageId)
    {
    }
    ~MqttEventData (){};

    public:
    std::string data;
    std::string topic;
};

class MqttAdapter : public IAdapter
{
    class MqttReceiver : public ::MqttReceiver::BnMqttReceiver
    {
        public:
        MqttReceiver (MqttAdapter &mqttAdapter) : mParent (mqttAdapter)
        {
        }
        MqttReceiver ()  = delete;
        ~MqttReceiver () = default;
        android::binder::Status onMqttReceived (const android::String16 &topic, const android::String16 &data)
        {
            mParent.onMqttReceived (android::String8 (topic).string (), android::String8 (data).string ());
            return android::binder::Status ();
        }

        private:
        MqttAdapter &mParent;
    };

    public:
    ~MqttAdapter (){};
    MqttAdapter ();
    void registerService ();
    void connect (std::string broker);
    void publish (std::string topic, std::string data);
    void subcribe (std::string topic, uint8_t qos);
    void onMqttReceived (std::string topic, std::string data);
    static MqttAdapter *getInstance ();
    void onBinderDied (const android::wp<android::IBinder> &who);

    private:
    android::sp<MqttServiceInterface::IMqttServiceInterface> mMqttSrv;
    android::sp<::MqttReceiver::BnMqttReceiver> receiver;
    android::sp<::android::IBinder> binder;
    android::sp<ServiceDeathRecipient> mServiceDeathRecipient;
};
} // namespace EmergencyCall

#endif /* MQTT_ADAPTER_H */