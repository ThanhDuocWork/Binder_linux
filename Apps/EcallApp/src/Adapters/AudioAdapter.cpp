#include "AudioAdapter.h"
#include "Logger.h"
namespace EmergencyCall
{
AudioAdapter::AudioAdapter ()
{
    mServiceDeathRecipient = new ServiceDeathRecipient ([this] (const android::wp<android::IBinder> &who) { this->onBinderDied (who); });
}

void AudioAdapter::playAudio (std::string filePath)
{
    if (mAudioSrv != nullptr)
    {
        int32_t flag = 0;
        mAudioSrv->PlayAudio (android::String16 (filePath.c_str ()), &flag);
    }
}

void AudioAdapter::stopAudio ()
{
    if (mAudioSrv != nullptr)
    {
        int32_t flag = 0;
        mAudioSrv->StopAudio (&flag);
    }
}

void AudioAdapter::handlePlayStateChanged (int currentState)
{
    std::shared_ptr<AudioEventData> audioEventData = std::make_shared<AudioEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::AUDIO_PLAY_STATE_CHANGED));
    audioEventData->mAudioStateChanged = currentState;
    /* Register new event data to handle it at ECall App side */
    MessageHandler::getInstance ()->addEventData (audioEventData);
}

void AudioAdapter::registerService ()
{
    /* Get audio service */
    mAudioSrv = android::interface_cast<AudioServiceInterface::IAudioServiceInterface> (
    android::defaultServiceManager ()->getService (android::String16 (binder_service::BINDER_AUDIO_SERVICE_NAME)));
    if (mAudioSrv != nullptr)
    {
        receiver = android::sp<AudioReceiver> (new AudioReceiver (*this));
        binder   = android::IInterface::asBinder (receiver.get ());
        mAudioSrv->registerReceiver (binder);
        android::ProcessState::self ()->startThreadPool ();
        android::IInterface::asBinder (mAudioSrv.get ())->linkToDeath (mServiceDeathRecipient);
        printLog_I ("registerService successfully");
    }
    else
    {
        std::shared_ptr<AudioEventData> audioEventData = std::make_shared<AudioEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::AUDIO_BINDER_DIED));
        /* Register new event data to handle it at ECall App side */
        MessageHandler::getInstance ()->addEventData (audioEventData, 500);
    }
}

AudioAdapter *AudioAdapter::getInstance ()
{
    static std::shared_ptr<AudioAdapter> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<AudioAdapter> ();
    }
    return instance.get ();
}

void AudioAdapter::onBinderDied (const android::wp<android::IBinder> &who)
{
    printLog_I ("Binder died");
    std::shared_ptr<AudioEventData> audioEventData = std::make_shared<AudioEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::AUDIO_BINDER_DIED));
    MessageHandler::getInstance ()->addEventData (audioEventData, 500);
}
} // namespace EmergencyCall
