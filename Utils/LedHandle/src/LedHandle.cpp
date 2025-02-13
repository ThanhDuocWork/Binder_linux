#include "LedHandle.h"

LedHandle::LedHandle(uint8_t pin, GPIODIRECTION hmiDirection, uint64_t duration, bool forever, 
    uint64_t timelow, uint64_t timehigh, uint64_t timegetting)
    : pin(pin), 
        interval(interval), 
        state(false), 
        gpioRaspberryPi(pin)
{
    this->duration = duration;
    this->timeHigh = timehigh;
    this->timeLow = timelow;
    this->timeGetting = timegetting;
    this->hmiDirection = hmiDirection;
    this->forever = forever;

    // Check time low, high, getting default
    if(timelow == 0 && timehigh == 0 || timegetting == 0)
    {
        interval = duration;
    }

    timer = std::make_unique<TimerHandler>([this]() {toggleValue();}, interval);
    timerDuration = std::make_unique<TimerHandler>([this]() {pause();}, duration);

    // Set direction for port gpio
    gpioRaspberryPi.setDirection(hmiDirection);
}

LedHandle::~LedHandle(){
    stop();
    gpioRaspberryPi.unExportGpio();
}

void LedHandle::start() 
{
    std::cout << "Timer Duration: " << duration << std::endl; 

    // Check and stop all thread timer on previous cycle
    timer->stop();
    timerDuration->stop();

    // Set time for timer high low and start
    timer->duration = interval;
    timer->start();

    // Set time for timer duration and start
    timerDuration->duration = duration;
    timerDuration->start();
}

void LedHandle::pause() {
    std::cout << "Timer duration pause" << std::endl; 
    // Check duration default and continue timer
    if(forever)
    {
        timer->active = true;
        timerDuration->active = true;
    }
    else
    {
        timer->active = false;
        timerDuration->active = false;
    }
}

void LedHandle::stop() 
{
    std::cout << "Timer TimeOut Stop Service:"<< duration;
    timer->stop();
    timerDuration->stop();
}

void LedHandle::toggleValue() 
{ 
    state = !state; 
    if(hmiDirection == GPIODIRECTION::INPUT)
    {
        digitalRead();
    }
    else if(hmiDirection == GPIODIRECTION::OUTPUT)
    {
        if ((timeHigh!=0) && (timeLow!=0))
        {
            if(state)
            {
                interval = timeHigh;
                std::cout << "Time timeHigh: " << interval;
            }
            else
            {
                interval = timeLow;
                std::cout << "Time timeLow: " << interval;
            }
        }
        else
        {
            interval = duration;
        }
        timer->duration = interval;

        digitalWrite(pin, state ? HIGH : LOW);
    }
    else
    {
        return;
    }
    
}

GPIOVALUE LedHandle::digitalRead() {
    std::cout << "Getting pin " << pin << std::endl;
    return gpioRaspberryPi.getValue();
}

void LedHandle::digitalWrite(int pin, bool state) {
    std::cout << "Setting pin " << pin << " to " << (state ? "HIGH" : "LOW") << std::endl; 
    // Set value for port gpio
    if(state)
    {
        gpioRaspberryPi.setValue(GPIOVALUE::HIGH);
    }
    else
    {
        gpioRaspberryPi.setValue(GPIOVALUE::LOW);
    }
}

bool LedHandle::ConfigGetting(uint64_t timeGetting)
{
    bool checkConfig = true;
    if(hmiDirection == GPIODIRECTION::OUTPUT)
    {
        std::cout << "Direction pin" << pin << " OUTPUT is not Getting value ";
        checkConfig = false;
    }
    else if(hmiDirection == GPIODIRECTION::INPUT)
    {
        this->timeGetting = timeGetting;
        // Firt active low time
        interval = timeGetting;
    }
    else
    {
        std::cout << "Direction pin" << pin << " not INPUT or OUTPUT ";
        checkConfig = false;
    }

    return checkConfig;
}

bool LedHandle::ConfigBlink(uint64_t timeLow, uint64_t timeHigh)
{
    bool checkConfig = true;
    if(hmiDirection == GPIODIRECTION::INPUT)
    {
        std::cout << "Direction pin" << pin << " INPUT is not Blink ";
        checkConfig = false;
    }
    else if(hmiDirection == GPIODIRECTION::OUTPUT)
    {
        this->timeLow = timeLow;
        this->timeHigh = timeHigh;
        // Firt active low time
        interval = timeLow;
    }
    else
    {
        std::cout << "Direction pin" << pin << " not INPUT or OUTPUT ";
        checkConfig = false;
    }
    return checkConfig;
}

void LedHandle::playLedPattern(ENUM_LED_PATTERN ledPattern)
{
    int low = 0;
    int high = 0;

    // Create a vector containing a struct of led pattern options
    vector<std::shared_ptr<dataLedPatter>> m_dataLedPatter{
        std::make_shared<dataLedPatter>(ENUM_LED_PATTERN::LED_PATTERN_UI_00_01, 500, 500),
        std::make_shared<dataLedPatter>(ENUM_LED_PATTERN::LED_PATTERN_UI_00_02, 1000, 1000)
    };

    // Check option ledPatter
    for(const auto& m_ledPatter : m_dataLedPatter)
    {
        if(ledPattern == (*m_ledPatter).m_numLedPatter)
        {
            low = (*m_ledPatter).m_timeLowLedPatter;
            high = (*m_ledPatter).m_timeHighLedPatter;
        }
    }
    
    stop();
    ConfigBlink(low, high);
    start();
}
