#ifndef TIME_HANDLER
#define TIME_HANDLER

#include <iostream>
#include <functional>
#include <chrono>
#include <thread>

class TimerHandler {
public:
    // Constructor
    TimerHandler() = delete;
    TimerHandler(std::function<void()> callback, uint duration)
        : callback(callback), duration(duration), active(false) {}

    // Destructor
    ~TimerHandler() = default;

    void start();

    void stop();

    // State active timer
    bool active;
    uint duration;

private:
    // Function will be called back when timeout
    std::function<void()> callback;
    std::thread thread;
};

#endif /*TIME_HANDLER*/
