#include "MessageHandler.h"

EventData::EventData (uint32_t messageId) : mMessageId (messageId), delayTime(0)
{
}

EventData::~EventData ()
{
}

int EventData::getMessageId ()
{
    return mMessageId;
}

MessageHandler::MessageHandler (int maxChildThread)
{
    mMaxChildThread = maxChildThread;
    mStop           = false;
}

MessageHandler::~MessageHandler ()
{
    stopThreadPool ();
}

void MessageHandler::startThreadPool ()
{
    for (int i = 0; i < mMaxChildThread; i++)
    {
        mChildThread.emplace_back ([this] { threadWorker (); });
    }
}

void MessageHandler::stopThreadPool ()
{
    {
        std::lock_guard<std::mutex> lock (mMutex);
        mStop = true;
    }
    for (std::thread &thread : mChildThread)
    {
        if (thread.joinable ())
        {
            thread.join ();
        }
    }
}

void MessageHandler::addEventData (std::shared_ptr<EventData> eventData, const uint32_t delayMs)
{
    if(eventData == nullptr)
        return;
    std::lock_guard<std::mutex> lock (mMutex);
    {
        eventData->delayTime = delayMs;
        std::shared_ptr<EventData> event = std::move (eventData);
        mEventDataList.emplace (event);
    }
}

void MessageHandler::checkmEventDataList ()
{
    std::cout << "mEventDataList " << mEventDataList.size () << std::endl;
}

void MessageHandler::registerEventHandler (EventHandler data)
{
    mEventHandler = data;
}

void MessageHandler::threadWorker ()
{
    while (!mStop)
    {
        std::shared_ptr<EventData> eventData;
        {
            std::lock_guard <std::mutex> lock (mMutex);
            if (mStop && mEventDataList.empty ())
            {
                return;
            }
            if (!mEventDataList.empty ())
            {
                eventData = mEventDataList.front ();
                mEventDataList.pop ();
            }
        }
        if(eventData.get() != nullptr)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(eventData->delayTime));
            mEventHandler (eventData);
        }
    }
}

MessageHandler *MessageHandler::getInstance ()
{
    static MessageHandler *mMessageHandler = new MessageHandler (10);
    return mMessageHandler;
}