#ifndef AUDIO_ADAPTER_H
#define AUDIO_ADAPTER_H
#include "AudioServiceInterface/IAudioServiceInterface.h"
#include "BnAudioReceiver.h"
#include "IAdapter.h"
#include "MessageHandler.h"
#include "ParameterDef.h"
#include "ServiceDeathRecipient.h"
#include <binder/IInterface.h>
#include <memory.h>

namespace EmergencyCall
{
class AudioEventData : public EventData
{
    public:
    AudioEventData () : EventData (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::AUDIO_PLAY_STATE_CHANGED))
    {
    }
    AudioEventData (uint32_t messageId) : EventData (messageId)
    {
    }
    ~AudioEventData (){};

    public:
    int32_t mAudioStateChanged;
};

class AudioAdapter : public IAdapter
{
    class AudioReceiver : public ::AudioReceiver::BnAudioReceiver
    {
        public:
        AudioReceiver (AudioAdapter &audioAdapter) : mParent (audioAdapter)
        {
        }
        AudioReceiver ()  = delete;
        ~AudioReceiver () = default;
        android::binder::Status onPlayStateChanged (int currentState)
        {
            mParent.handlePlayStateChanged (currentState);
            return android::binder::Status ();
        }

        private:
        AudioAdapter &mParent;
    };

    public:
    ~AudioAdapter (){};
    AudioAdapter ();
    void registerService ();
    void playAudio (std::string filePath);
    void stopAudio ();
    void handlePlayStateChanged (int currentState);
    static AudioAdapter *getInstance ();
    void onBinderDied (const android::wp<android::IBinder> &who);

    private:
    android::sp<AudioServiceInterface::IAudioServiceInterface> mAudioSrv;
    android::sp<AudioReceiver> receiver;
    android::sp<::android::IBinder> binder;
    android::sp<ServiceDeathRecipient> mServiceDeathRecipient;
};
} // namespace EmergencyCall
#endif /* AUDIO_ADAPTER_H */
