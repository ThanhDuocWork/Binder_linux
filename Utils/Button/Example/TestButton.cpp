#include "../Inc/Button.h"

class testButton : public Button
{
public:
    testButton() = delete;
    testButton(int64_t pinButton, int64_t timeShort = 200, int64_t timeLong = 2000, int64_t timeStuck = 5000) 
    : Button(pinButton, timeShort, timeLong, timeStuck) {};
    
    ~testButton() = default;

    void press() override {
        std::cout << "Hello from testButton press Event" << std::endl;
    }

    void release() override {
        std::cout << "Hello from testButton Release Event" << std::endl;
    }

    void shortPress() override {
        std::cout << "Hello from testButton Short Press Event" << std::endl;
    }

    void longPress() override {
        std::cout << "Hello from testButton Long Press Event" << std::endl;
    }

    void stuck() override {
        std::cout << "Hello from testButton Stuck Press Event" << std::endl;
    }
};

int main() {
    // Button button(21);
    testButton m_testButton(23);

    // bool testPull = button.pullUpDnControll(GPIOVALUE::HIGH);
    bool testPull = m_testButton.pullUpDnControll(GPIOVALUE::HIGH);
    std::cout << "return pull: " << testPull << std::endl;

    // button.startHandle();
    m_testButton.startHandle();

    // button.stop();
    // m_testButton.stop();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Main run" << std::endl;
    }

    return 0;
}
