#ifndef _IAPPLICATION_H
#define _IAPPLICATION_H
class IApplication
{
private:
    /* data */
public:
    virtual void onCreate() = 0;
    virtual void onDestroy() = 0;
    virtual void onBootCompleted() = 0;
    virtual void onLooper() = 0;
    IApplication() = default;
    ~IApplication() = default;
};
#endif