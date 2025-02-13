#include "TimerHandler.h" 

void TimerHandler::start() {
    if (!active) {
    active = true;
    std::cout << "Timer Start" << std::endl;

    thread = std::thread([this]() {
        while (active) {
            for(int i = 0; i < (duration/10); i++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                if(!active)
                {
                    i = duration;
                    break;
                }
            }
            if (active) {
                std::cout << "Timeout callback" << std::endl;
                callback();
            }
        }
    });
    }
}

void TimerHandler::stop() {

    active = false;
    if (thread.joinable()) {
        thread.join();
    }
    std::cout << "Timer Stop" << std::endl;
} 