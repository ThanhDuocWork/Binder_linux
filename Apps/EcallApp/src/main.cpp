#include "ECallApp.h"
#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    printLog_I("Start ECall Application");
    ApplicationBase *eCallApplication = ApplicationBase::createApplication(new ECallApp());
    eCallApplication->run();
    return 0;
}