#ifndef CANCELTIMERSTATE_H
#define CANCELTIMERSTATE_H
#include "IState.h"
#include "FeatureTimer.h"
#include "Logger.h"
#include <memory.h>
#include "TransitionTable.h"
#include "InputProcess.h"
class CancelTimerState : public IState
{
private:
    bool flag;
    std::shared_ptr<Timer> actionCancelTimer;
public:
    CancelTimerState();
    void handleAction() override;
    void preEnterState() override;
    void preReleaseState() override;
    static IState* getInstance();
    eState getStateID() override{
        return eState::eState_CancelTimer;
    }
};
#endif