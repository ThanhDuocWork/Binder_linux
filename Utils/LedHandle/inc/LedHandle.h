#ifndef LED_HANDLER
#define LED_HANDLER

#include <functional>
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <memory>

#include "TimerHandler.h"
#include "gpioRaspberryPi.h"

enum ENUM_LED_PATTERN
{
    // Blink 0,5s
    LED_PATTERN_UI_00_01,
    // Blink 1s
    LED_PATTERN_UI_00_02
};

struct dataLedPatter{

    ENUM_LED_PATTERN m_numLedPatter;
    uint64_t m_timeLowLedPatter;
    uint64_t m_timeHighLedPatter;

    dataLedPatter(ENUM_LED_PATTERN numLedPatter, uint64_t timeLowLedPatter = 0, uint64_t timeHighLedPatter = 0)
    :m_numLedPatter(numLedPatter), m_timeLowLedPatter(timeLowLedPatter), m_timeHighLedPatter(timeHighLedPatter){}

};

class LedHandle
{
public:
    // Constructor
    LedHandle() = delete;
    LedHandle(uint8_t pin, GPIODIRECTION hmiDirection, uint64_t duration, bool forever = false,
        uint64_t timelow = 0, uint64_t timehigh = 0, uint64_t timegetting = 0);
    // Destructor
    ~LedHandle();
    
    // Start led handle
    void start();
    // Stop led handle
    void stop();
    // Bink() port GPIO
    bool ConfigBlink(uint64_t timeLow, uint64_t timeHigh);
    // Getting value port GPIO
    bool ConfigGetting(uint64_t timeGetting);
    // Get value for port GPIO
    GPIOVALUE digitalRead();
    // Play blink led pattern 0,5s or 1s
    void playLedPattern(ENUM_LED_PATTERN ledPattern);

private:
    uint8_t pin;    // ID port gpio
    bool state; // State Port
    bool forever;   // Option Forever
    uint64_t duration;  // Active period of port ID
    uint64_t timeHigh;  // Port time is high 
    uint64_t timeLow;   // Port time is low
    uint64_t timeGetting;   // Time get value of port
    uint64_t interval;      // Time period control
    GpioRaspberryPi gpioRaspberryPi;
    GPIODIRECTION hmiDirection;
    std::unique_ptr<TimerHandler> timer;
    std::unique_ptr<TimerHandler> timerDuration;

    // Pause time when the timer be ended
    void pause();
    // Check port GPIO and reverse its state
    void toggleValue();
    // Set value for port GPIO
    void digitalWrite(int pin, bool state);
};

#endif /*LED_HANDLER*/