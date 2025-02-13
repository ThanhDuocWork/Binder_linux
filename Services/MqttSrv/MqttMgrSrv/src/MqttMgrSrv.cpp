#include "MqttMgrSrv.h"

::android::binder::Status MqttMgrSrv::registerReceiver(const ::android::sp<::android::IBinder> &binder)
{
    android::sp<MqttReceiver::IMqttReceiver> receiver = android::interface_cast<MqttReceiver::IMqttReceiver>(binder);
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

void MqttMgrSrv::onMqttReceived (std::string topic, std::string data)
{
    if (!mReceiverList.empty())
    {
        android::sp<MqttReceiver::IMqttReceiver> obj{mReceiverList.front()};
        if (obj == nullptr)
        {
            printLog_I("obj is nullptr");
        }
        else
        {
            obj->onMqttReceived(android::String16(topic.c_str()), android::String16(data.c_str()));
        }
    }
}

::android::binder::Status MqttMgrSrv::Connect(const ::android::String16 &broker)
{
    printLog_I("Connect to %s ...", toString(broker).c_str());
    std::this_thread::sleep_for(std::chrono::seconds(5));

    printLog_I("Connected success !!!");
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return ::android::binder::Status::ok();
}

::android::binder::Status MqttMgrSrv::Disconnect()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    printLog_I("Disconnect successfully !!!");
    return ::android::binder::Status::ok();
}

::android::binder::Status MqttMgrSrv::Subscribe(const ::android::String16 &topic)
{
    printLog_I("Subscribe to %s ...", toString(topic).c_str());
    std::this_thread::sleep_for(std::chrono::seconds(5));

    printLog_I("Subscribe successfully !!!");

    return ::android::binder::Status::ok();
}

::android::binder::Status MqttMgrSrv::Publish(const ::android::String16 &topic, const ::android::String16 &payload)
{
    printLog_I("Publish to %s, message: %s.", toString(topic).c_str(), toString(payload).c_str());
    std::this_thread::sleep_for(std::chrono::seconds(5));

    printLog_I("Finished !!!");

    return ::android::binder::Status::ok();
}
