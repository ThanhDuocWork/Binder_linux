#ifndef __MESSAGE_HANDLER_H
#define __MESSAGE_HANDLER_H

#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include "Logger.h"

class EventData
{
    public:
    EventData () = delete;
    EventData (uint32_t messageId);
    virtual ~EventData ();
    int getMessageId ();
    uint32_t delayTime;

    protected:
    int mMessageId;
};

using EventHandler = std::function<void (std::shared_ptr<EventData>)>;

class MessageHandler
{
    public:
    ~MessageHandler ();
    void startThreadPool ();
    void stopThreadPool ();
    void addEventData (std::shared_ptr<EventData> eventData, const uint32_t delayMs = 0);
    void registerEventHandler (EventHandler data);
    void checkmEventDataList ();
    static MessageHandler *getInstance ();

    private:
    MessageHandler (int maxChildThread);
    std::vector<std::thread> mChildThread;
    std::queue<std::shared_ptr<EventData>> mEventDataList;
    std::mutex mMutex;
    EventHandler mEventHandler;
    bool mStop;
    int mMaxChildThread;
    void threadWorker ();
};

#endif
