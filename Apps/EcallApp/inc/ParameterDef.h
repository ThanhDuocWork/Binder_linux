#ifndef MESSAGE_DEF_H 
#define MESSAGE_DEF_H
#include <iostream>
namespace message
{
    enum class ENUM_INTERNAL_MESSAGE : uint32_t
    {
        /* Audio */
        AUDIO_PLAY_STATE_CHANGED = 0,
        AUDIO_BINDER_DIED,

        /* HMI */
        HMI_EVENT_RECEIVED,
        HMI_BINDER_DIED,

        /* MQTT */
        MQTT_EVENT_RECEIVED,
        MQTT_BINDER_DIED,

        /* The lass item */
        UNKNOWN
    };

    static std::map<ENUM_INTERNAL_MESSAGE, std::string> messageStringMap
    {
        {ENUM_INTERNAL_MESSAGE::AUDIO_PLAY_STATE_CHANGED, "AUDIO_PLAY_STATE_CHANGED"},
        {ENUM_INTERNAL_MESSAGE::AUDIO_BINDER_DIED, "AUDIO_BINDER_DIED"},
        {ENUM_INTERNAL_MESSAGE::HMI_EVENT_RECEIVED, "HMI_EVENT_RECEIVED"},
        {ENUM_INTERNAL_MESSAGE::HMI_BINDER_DIED, "HMI_BINDER_DIED"},
        {ENUM_INTERNAL_MESSAGE::MQTT_EVENT_RECEIVED, "MQTT_EVENT_RECEIVED"},
        {ENUM_INTERNAL_MESSAGE::MQTT_BINDER_DIED, "MQTT_BINDER_DIED"},
        {ENUM_INTERNAL_MESSAGE::UNKNOWN, "UNKNOWN"}
    };
}

namespace binder_service
{
    constexpr const char * BINDER_HMI_SERVICE_NAME = "HMIMgrSrv";
    constexpr const char * BINDER_AUDIO_SERVICE_NAME = "AudioMgrSrv";
    constexpr const char * BINDER_MQTT_SERVICE_NAME = "MqttMgrSrv";
} // namespace service_binder



#endif /* MESSAGE_DEF_H */