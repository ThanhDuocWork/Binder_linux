#include "Button.h"

// Constructor and Config state time press
Button::Button(int64_t pinButton, int64_t timeShort, int64_t timeLong, int64_t timeStuck) 
    : handleActive(false), gpioRaspberryPi(pinButton)
{
    this->timeShortPress = timeShort;
    this->timeLongPress = timeLong;
    this->timeStuckPress = timeStuck;

    // Set direction for port gpio
    gpioRaspberryPi.setDirection(GPIODIRECTION::INPUT);
}

Button::~Button()
{
    // Unexport gpio
    gpioRaspberryPi.unExportGpio();
}

void Button::startHandle() 
{
    if (!handleActive) {
        handleActive = true;
        eventThread = std::thread([this](){
            std::chrono::steady_clock::time_point startPress;
            std::chrono::steady_clock::time_point continuePress;
            bool isFirstPress = false;
            bool shortPressDone = false;
            bool longPressDone = false;
            bool stuckPressDone = false;

            while(handleActive){
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                GPIOVALUE valueInput = gpioRaspberryPi.getValue();

                // check first press
                if(valueInput == pullContr && !isFirstPress){
                    startPress = std::chrono::steady_clock::now();
                    press();
                    isFirstPress = true;
                }
                // check is on hold
                else if(valueInput == pullContr && isFirstPress){
                    continuePress = std::chrono::steady_clock::now();
                }
                // check release
                else if(valueInput != pullContr && isFirstPress){
                    release();
                    // reset time press
                    startPress = std::chrono::steady_clock::now();
                    // reset press state is first
                    isFirstPress = false;
                    shortPressDone = false;
                    longPressDone = false;
                    stuckPressDone = false;
                }

                // check time press
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(continuePress - startPress).count();
                if(elapsed >= timeShortPress && !shortPressDone) {
                    shortPress();
                    shortPressDone = true;
                }else if(elapsed >= timeLongPress && !longPressDone) {
                    longPress(); 
                    longPressDone = true;
                }else if(elapsed >= timeStuckPress && !stuckPressDone) {
                    stuck(); 
                    stuckPressDone = true;
                }
            } 
        });
    }
}

void Button::stopHandle()
{
    handleActive = false;
    if (eventThread.joinable()) {
        eventThread.join();
    }
}

bool Button::pullUpDnControll(GPIOVALUE pullContr)
{
    this->pullContr = pullContr;
    return pullContr;
}

void Button::press() {
    std::cout << "Press Event" << std::endl;
}

void Button::release() {
    std::cout << "Release Event" << std::endl;
}

void Button::shortPress() {
    std::cout << "Short Press Event" << std::endl;
}

void Button::longPress() {
    std::cout << "Long Press Event" << std::endl;
}

void Button::stuck() {
    std::cout << "Stuck Event" << std::endl;
}