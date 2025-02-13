#include "../Inc/LedHandle.h"


int main() {

    LedHandle m_ledPattern2(23, GPIODIRECTION::OUTPUT, 10000);

    m_ledPattern2.playLedPattern(ENUM_LED_PATTERN::LED_PATTERN_UI_00_01);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    m_ledPattern2.playLedPattern(ENUM_LED_PATTERN::LED_PATTERN_UI_00_02);

    std::this_thread::sleep_for(std::chrono::seconds(15));

    m_ledPattern2.stop();


    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
