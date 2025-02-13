#include "ApplicationBase.h"

ApplicationBase *ApplicationBase::instance = nullptr;

void ApplicationBase::onCreate ()
{
    printLog_I("Create Application");
}

void ApplicationBase::onDestroy ()
{
    printLog_I("Destroy Application");
}

void ApplicationBase::onBootCompleted ()
{
    printLog_I("Boot Completed");
}

void ApplicationBase::onLooper ()
{
}

void ApplicationBase::handleSignal()
{
    instance = this;
    std::signal(SIGINT, signalHandler);
}

void ApplicationBase::signalHandler(int sig_num)
{
    instance->mApp->onDestroy();
    exit(0);
}

ApplicationBase *ApplicationBase::createApplication(IApplication *newApp)
{
    static ApplicationBase *app = new ApplicationBase();
    app->mApp = newApp;
    return app;
}

void ApplicationBase::run()
{
    handleSignal();
    mApp->onCreate();
    mApp->onBootCompleted();
    while (true)
    {
        mApp->onLooper();
    }
}
