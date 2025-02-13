#ifndef _APPLICATION_BASE_H
#define _APPLICATION_BASE_H
#include <stdint.h>
#include <csignal>
#include <functional>
#include <thread>
#include "IApplication.h"
#include "Logger.h"
class ApplicationBase : public IApplication
{
    private:
    int16_t pid;
    IApplication *mApp;
    static ApplicationBase *instance;
    virtual void handleSignal();
    
    public:
    virtual void onCreate () override;
    virtual void onDestroy () override;
    virtual void onBootCompleted () override;
    virtual void onLooper () override;
    static ApplicationBase *createApplication(IApplication *newApp);
    void run();
    static void signalHandler(int sig_num);
};
#endif