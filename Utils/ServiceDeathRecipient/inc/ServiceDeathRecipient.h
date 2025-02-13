#ifndef SERVICE_DEATH_RECIPIENT_H
#define SERVICE_DEATH_RECIPIENT_H
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <functional>
namespace EmergencyCall
{
class ServiceDeathRecipient : public android::IBinder::DeathRecipient
{
    public:
    ServiceDeathRecipient (const std::function<void (const android::wp<android::IBinder> &who)> onBinderDied) : mOnBinderDied (onBinderDied)
    {
    }

    virtual void binderDied (const android::wp<android::IBinder> &who) override
    {
        mOnBinderDied (who);
    }

    private:
    std::function<void (const android::wp<android::IBinder> &who)> mOnBinderDied;
};
} // namespace EmergencyCall
#endif