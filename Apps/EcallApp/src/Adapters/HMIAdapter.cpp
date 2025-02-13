#include "HMIAdapter.h"
#include "Logger.h"
namespace EmergencyCall
{

HMIAdapter::HMIAdapter ()
{
    mServiceDeathRecipient = new ServiceDeathRecipient ([this] (const android::wp<android::IBinder> &who) { this->onBinderDied (who); });
}

void HMIAdapter::requestLedPattern (std::string pattern)
{
    if (mHMISrv != nullptr)
    {
        mHMISrv->requestLedPattern (android::String16 (pattern.c_str ()));
    }
}

void HMIAdapter::onHMIReceived (std::string data)
{
    std::shared_ptr<HMIEventData> hmiEventData = std::make_shared<HMIEventData> ();
    printLog_I("Received data from HMIReceiver:");
    hmiEventData->setData (data);
    /* Register new event data to handle it at ECall App side */
    MessageHandler::getInstance ()->addEventData (hmiEventData);
}

void HMIAdapter::registerService ()
{
    /* Get audio service */
    mHMISrv = android::interface_cast<HMIServiceInterface::IHMIServiceInterface> (
    android::defaultServiceManager ()->getService (android::String16 (binder_service::BINDER_HMI_SERVICE_NAME)));
    if (mHMISrv != nullptr)
    {
        receiver = android::sp<HMIReceiver> (new HMIReceiver (*this));
        binder   = android::IInterface::asBinder (receiver.get ());
        mHMISrv->registerReceiver (binder);
        android::ProcessState::self ()->startThreadPool ();
        android::IInterface::asBinder (mHMISrv.get ())->linkToDeath (mServiceDeathRecipient);
        printLog_I ("registerService successfully");
    }
    else
    {
        std::shared_ptr<HMIEventData> hmiEventData = std::make_shared<HMIEventData> (static_cast<uint32_t>
        (message::ENUM_INTERNAL_MESSAGE::HMI_BINDER_DIED)); hmiEventData->setData ("HMI_BINDER_DIED");
        /* Register new event data to handle it at ECall App side */
        MessageHandler::getInstance ()->addEventData (hmiEventData, 500);
    }
}

HMIAdapter *HMIAdapter::getInstance ()
{
    static std::shared_ptr<HMIAdapter> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<HMIAdapter> ();
    }
    return instance.get ();
}

void HMIAdapter::onBinderDied (const android::wp<android::IBinder> &who)
{
    printLog_I ("Binder died");
    std::shared_ptr<HMIEventData> hmiEventData = std::make_shared<HMIEventData> (static_cast<uint32_t> (message::ENUM_INTERNAL_MESSAGE::HMI_BINDER_DIED));
    hmiEventData->setData ("HMI_BINDER_DIED");
    MessageHandler::getInstance ()->addEventData (hmiEventData, 500);
}
} // namespace EmergencyCall
