#include "../Inc/gpioRaspberryPi.h"

int main()
{
    GpioRaspberryPi m_gpioRaspberryPiPort20(20);
    GpioRaspberryPi m_gpioRaspberryPiPort21(21);
    m_gpioRaspberryPiPort20.setDirection(GPIODIRECTION::OUTPUT);
    m_gpioRaspberryPiPort21.setDirection(GPIODIRECTION::OUTPUT);    
    while (1) {
        m_gpioRaspberryPiPort20.setValue(GPIOVALUE::HIGH);
        usleep(1000000);
        m_gpioRaspberryPiPort20.setValue(GPIOVALUE::LOW);
        usleep(1000000);
        m_gpioRaspberryPiPort21.setValue(GPIOVALUE::HIGH);
        usleep(1000000);
        m_gpioRaspberryPiPort21.setValue(GPIOVALUE::LOW);
        usleep(1000000);
    }	
    return 0;
}