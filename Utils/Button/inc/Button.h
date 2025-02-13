#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include "gpioRaspberryPi.h"

class Button {
private:
    std::atomic<bool> handleActive; // state press
    int64_t timeShortPress;  // time event Short press
    int64_t timeLongPress;   // time event Long press
    int64_t timeStuckPress;  // time event Stuck press
    GPIOVALUE pullContr; // control pull up or down 
    GpioRaspberryPi gpioRaspberryPi;
    std::thread eventThread;

public:
    // Constructor
    Button() = delete;
    Button(int64_t pinButton, int64_t timeShort = 200, int64_t timeLong = 2000, int64_t timeStuck = 5000);

    // Destructor
    ~Button();

    void startHandle();
    void stopHandle();
    bool pullUpDnControll(GPIOVALUE pullContr = GPIOVALUE::LOW);

protected:
    virtual void press();
    virtual void release();
    virtual void shortPress();
    virtual void longPress();
    virtual void stuck();
};