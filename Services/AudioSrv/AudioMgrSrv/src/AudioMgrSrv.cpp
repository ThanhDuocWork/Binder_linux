#include "AudioMgrSrv.h"
#include "Logger.h"

::android::binder::Status AudioMgrSrv::PlayAudio(const ::android::String16 &filePath, int32_t *_aidl_return)
{
    android::String8 string8(filePath);
    *_aidl_return = 0;
    FLAG_AUDIO statusAudio = FLAG_AUDIO::OK;

    //----------------------------------------------------------------

    // statusAudio = openFileWav(string8.string());
    // if(statusAudio != FLAG_AUDIO::OK)
    // {
    //     *_aidl_return = static_cast<int32_t>(statusAudio);
    //     return ::android::binder::Status::ok();
    // }
    // statusAudio = openDevice();
    // if(statusAudio != FLAG_AUDIO::OK)
    // {
    //     *_aidl_return = static_cast<int32_t>(statusAudio);
    //     return ::android::binder::Status::ok();
    // }
    // statusAudio = allocateHardware();
    // if(statusAudio != FLAG_AUDIO::OK)
    // {
    //     *_aidl_return = static_cast<int32_t>(statusAudio);
    //     return ::android::binder::Status::ok();
    // }
    // thread threadPlay(&AudioMgrSrv::playAudio, this);
    // threadPlay.detach(); // Separate threads to run independently
    // *_aidl_return = static_cast<int32_t>(statusAudio);

    //----------------------------------------------------------------

    //----------------------------------------------------------------
    printLog_I("Open file %s success !!!", filePath);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    printLog_I("Open device success !!!");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    printLog_I("Allocate hardware success !!!");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    thread threadPlay(&AudioMgrSrv::playAudio, this);
    threadPlay.detach(); // Separate threads to run independently
    *_aidl_return = static_cast<int32_t>(statusAudio);
    //----------------------------------------------------------------

    return ::android::binder::Status::ok();
}

::android::binder::Status AudioMgrSrv::StopAudio(int32_t *_aidl_return)
{
    FLAG_AUDIO statusAudio = FLAG_AUDIO::OK;
    *_aidl_return = static_cast<int32_t>(statusAudio);
    stopAudio();
    return ::android::binder::Status::ok();
}

::android::binder::Status AudioMgrSrv::callBack()
{
    printLog_I("mReceiverList.size %d", mReceiverList.size());
    if (!mReceiverList.empty())
    {
        int32_t number = 12;
        ::android::sp<AudioReceiver::IAudioReceiver> obj = mReceiverList.front();
        if (obj == nullptr)
        {
           printLog_I("obj is nullptr");
        }
        obj->onPlayStateChanged(number);
    }
    else
    {
        printLog_I("mReceiverList is nullptr");
    }
    return ::android::binder::Status::ok();
}

::android::binder::Status AudioMgrSrv::registerReceiver(const ::android::sp<::android::IBinder> &binder)
{
    ::android::sp<AudioReceiver::IAudioReceiver> receiver = android::interface_cast<AudioReceiver::IAudioReceiver>(binder);
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

void AudioMgrSrv::PlayStateChanged(FLAG_AUDIO stateCurrent)
{
    if (!mReceiverList.empty())
    {
        ::android::sp<AudioReceiver::IAudioReceiver> obj{mReceiverList.front()};
        if (obj == nullptr)
        {
            printLog_I("obj is nullptr");
        }
        obj->onPlayStateChanged(static_cast<int32_t>(stateCurrent));
    }
}