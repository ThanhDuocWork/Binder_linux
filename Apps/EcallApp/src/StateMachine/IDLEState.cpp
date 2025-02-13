#include "IDLEState.h"
void IDLEState::preEnterState()
{
    printLog_I("Wait for user SOS button!!");
}
void IDLEState::handleAction()
{
    std::string globalKey = HMIMgrSrv::getInstance()->getGlobalKey();
    if (globalKey=="s")
    {
        printLog_I("User press button");
        HMIMgrSrv::getInstance()->onHMIReceived(globalKey);
        TransitionTable::getInstance()->setState(this->getStateID(), eState::eState_CancelTimer);
        printLog_I("--------------------------------");
    } 
}
void IDLEState::preReleaseState()
{
    HMIMgrSrv::getInstance()->setGlobalKey("");
    printLog_I("preReleaseState to IDLEState");
}
IState *IDLEState::getInstance()
{
    static std::shared_ptr<IDLEState> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<IDLEState>();
    }
    return instance.get();
}