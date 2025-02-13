#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
using namespace std;

enum GPIOVALUE
{
    LOW,
    HIGH
};

enum GPIODIRECTION
{
    INPUT,
    OUTPUT
};

class GpioRaspberryPi
{
public:
    // Constructor
    GpioRaspberryPi() = delete;
    // Destructor
    ~GpioRaspberryPi() = default;

    // Constructor export GPIO
    GpioRaspberryPi(int Idgpio);
	    
    // Function unexport GPIO
    void unExportGpio();

    // Function set direction for GPIO
    bool setDirection(GPIODIRECTION option);
        
    // Function set value for GPIO
    bool setValue(GPIOVALUE value);

    // Function get value for GPIO
    GPIOVALUE getValue();

private:
    int Idgpio; //ID port gpio
    GPIODIRECTION Option;
    string linkConfigValue;

};
