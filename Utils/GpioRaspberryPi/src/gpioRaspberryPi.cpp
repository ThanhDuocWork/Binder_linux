#include "gpioRaspberryPi.h"

using namespace std;

GpioRaspberryPi::GpioRaspberryPi(int Idgpio)
{
    this->Idgpio = Idgpio;

    // Set path file set value gpio
    linkConfigValue = "/sys/class/gpio/gpio";
    // Add ID GPIO into link path
    linkConfigValue += to_string(this->Idgpio);
    // Add "/value" into link path
    linkConfigValue += "/value";

    // Path export gpio
    string linkConfig = "/sys/class/gpio/export";	
    printf("Link export: %s \n", linkConfig.c_str());

    FILE* fptr;
    // Open file /sys/class/gpio/export
    fptr = fopen(linkConfig.c_str(), "w");

    // Check file path /sys/class/gpio/export is correct
    if (fptr == NULL) {
        printf("Error!, file path export not correct\n");
        exit(1);
    }	    
    // Enter Id GPIO into file export
    fprintf(fptr, "%d", Idgpio);
    fclose(fptr);
    printf("Export gpio%d success\n\n", Idgpio);
    usleep(1000);
}

void GpioRaspberryPi::unExportGpio()
{
    // Path unexport gpio
    string linkConfig = "/sys/class/gpio/unexport";	
    printf("Link unexport: %s \n", linkConfig.c_str());

    FILE* fptr;
    // Open file /sys/class/gpio/export
    fptr = fopen(linkConfig.c_str(), "w");

    // Check file path /sys/class/gpio/unexport is correct
    if (fptr == NULL) {
        printf("Error!, file path unexport not correct\n");
        exit(1);
    }	    
    // Enter Id GPIO into file export
    fprintf(fptr, "%d", Idgpio);
    fclose(fptr);
    printf("Unexport gpio%d success\n\n", Idgpio);
    usleep(1000);
}

bool GpioRaspberryPi::setDirection(GPIODIRECTION option)
{
    this->Option = option;
    bool reOption;
    // Path file gpio
    string linkConfig = "/sys/class/gpio/gpio";
    // Add ID GPIO into link path
    linkConfig += to_string(this->Idgpio);
    // Add "/direction" into link path
    linkConfig += "/direction";	
    printf("Link direction: %s \n", linkConfig.c_str());

    FILE* fptr;
    // Open file /sys/class/gpio/export
    fptr = fopen(linkConfig.c_str(), "w");    
    // Check file path /sys/class/gpio/Idgpio/direction is correct
    if (fptr == NULL) {
        printf("Error!, port gpio%d have not export \n", Idgpio);
    }

    if (Option == GPIODIRECTION::INPUT)
    {
        fprintf(fptr, "%s", "in");
        reOption = true;
        printf("GPIO%d direction is INPUT \n\n", Idgpio);
    }
    else
    {
        fprintf(fptr, "%s", "out");
        reOption = false;
        printf("GPIO%d direction is OUTPUT \n\n", Idgpio);
    }	
    fclose(fptr);	    
    return reOption;
}

bool GpioRaspberryPi::setValue(GPIOVALUE value)
{
    if (Option == GPIODIRECTION::INPUT)
    {
        printf("GPIO%d can not controll value because direction is INPUT \n", Idgpio);
        exit(1);
    }

    bool reValue;    
    printf("Link value: %s \n", linkConfigValue.c_str());

    FILE* fptr;    
    // Open file /sys/class/gpio/export
    fptr = fopen(linkConfigValue.c_str(), "w");    
    // Check file path /sys/class/gpio/Idgpio/direction is correct
    if (fptr == NULL) {
        printf("Error!, port gpio%d have not export \n", Idgpio);
    }    
    if (value == GPIOVALUE::HIGH)
    {
        fprintf(fptr, "%d", 1);
        reValue = true;
        printf("GPIO%d value is HIGH \n\n", Idgpio);
    }
    else
    {
        fprintf(fptr, "%d", 0);
        reValue = false;
        printf("GPIO%d value is LOW \n\n", Idgpio);
    }    
    fclose(fptr);    
    return reValue;
}

GPIOVALUE GpioRaspberryPi::getValue()
{
    if (Option == GPIODIRECTION::OUTPUT)
    {
        printf("GPIO%d can not get value because direction is OUTPUT \n", Idgpio);
        exit(1);
    }

    int num = 0;  
    printf("Link value: %s \n", linkConfigValue.c_str());

    FILE* fptr;    
    // Open file /sys/class/gpio/export
    fptr = fopen(linkConfigValue.c_str(), "r");    
    // Check file path /sys/class/gpio/Idgpio/direction is correct
    if (fptr == NULL) {
        printf("Error!, port gpio%d have not export \n", Idgpio);
    }    
    fscanf(fptr, "%d", &num);
    printf("GPIO%d get value: %d \n\n", Idgpio, num); 
    fclose(fptr);
    if(num == 0)
    {return GPIOVALUE::LOW;}
    else
    {return GPIOVALUE::HIGH;}
}