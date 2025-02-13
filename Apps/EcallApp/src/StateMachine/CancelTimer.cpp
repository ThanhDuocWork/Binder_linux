#include "CancelTimerState.h"
CancelTimerState::CancelTimerState()
{
    actionCancelTimer = std::make_shared<Timer>();
}
IState *CancelTimerState::getInstance()
{
    static std::shared_ptr<CancelTimerState> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<CancelTimerState>();
    }
    return instance.get();
}
void CancelTimerState::preEnterState()
{
    printLog_I("void CancelTimerState::preEnterState()");
}
void CancelTimerState::handleAction()
{

        printLog_I("CancelTimerState::handleAction()");

}
void CancelTimerState::preReleaseState()
{


    printLog_I("preReleaseState CancelTimerState ");
}