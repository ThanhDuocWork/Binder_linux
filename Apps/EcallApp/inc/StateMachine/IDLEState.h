#ifndef IDLESTATE_H
#define IDLESTATE_H
#include "IState.h"
#include "Logger.h"
#include <memory.h>
#include <TransitionTable.h>
//#include "HMIAdapter.h"
#include "HMIMgrSrv.h"
class IDLEState : public IState
{
private:

public:
    IDLEState()=default;
    void handleAction() override;
    void preEnterState() override;
    void preReleaseState() override;
    static IState* getInstance();
    eState getStateID()override{
        return eState::eState_IDLE;
    }
};
#endif
