#include "MqttAdapter.h"
#include "Logger.h"
namespace EmergencyCall
{

MqttAdapter::MqttAdapter ()
{
    mServiceDeathRecipient = new ServiceDeathRecipient ([this] (const android::wp<android::IBinder> &who) { this->onBinderDied (who); });
}

void MqttAdapter::connect (std::string broker)
{
    if (mMqttSrv != nullptr)
    {
    }
}

void MqttAdapter::onMqttReceived (std::string topic, std::string data)
{
    std::shared_ptr<MqttEventData> mqttEventData = std::make_shared<MqttEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::MQTT_EVENT_RECEIVED));
    mqttEventData->topic = topic;
    mqttEventData->data  = data;
    /* Register new event data to handle it at ECall App side */
    MessageHandler::getInstance ()->addEventData (mqttEventData);
}

void MqttAdapter::registerService ()
{
    /* Get mqtt service */
    mMqttSrv = android::interface_cast<MqttServiceInterface::IMqttServiceInterface> (
    android::defaultServiceManager ()->getService (android::String16 (binder_service::BINDER_MQTT_SERVICE_NAME)));
    if (mMqttSrv != nullptr)
    {
        receiver = android::sp<MqttReceiver> (new MqttReceiver (*this));
        binder   = android::IInterface::asBinder (receiver.get ());
        mMqttSrv->registerReceiver (binder);
        android::ProcessState::self ()->startThreadPool ();
        android::IInterface::asBinder (mMqttSrv.get ())->linkToDeath (mServiceDeathRecipient);
        printLog_I ("registerService successfully");
    }
    else
    {
        std::shared_ptr<MqttEventData> audioEventData = std::make_shared<MqttEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::MQTT_BINDER_DIED));
        /* Register new event data to handle it at ECall App side */
        MessageHandler::getInstance ()->addEventData (audioEventData, 500);
    }
}

MqttAdapter *MqttAdapter::getInstance ()
{
    static std::shared_ptr<MqttAdapter> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<MqttAdapter> ();
    }
    return instance.get ();
}

void MqttAdapter::onBinderDied (const android::wp<android::IBinder> &who)
{
    printLog_I ("Binder died");
    std::shared_ptr<MqttEventData> mqttEventData = std::make_shared<MqttEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::MQTT_BINDER_DIED));
    MessageHandler::getInstance ()->addEventData (mqttEventData, 500);
}
} // namespace EmergencyCall
