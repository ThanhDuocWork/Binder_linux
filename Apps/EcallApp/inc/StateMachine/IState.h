#ifndef ISTATE_H
#define ISTATE_H
#include "Logger.h"
#include <iostream>
#include <map>

enum eState : uint32_t
{
    eState_IDLE = 0,
    eState_CancelTimer,
    eState_Center,
    eState_ActiveData,
    eState_NonActiveData,
};

const std::map<eState, std::string> stateStringName{ { eState_IDLE, "eState_IDLE" }, { eState_CancelTimer, "eState_CancelTimer" },
    { eState_Center, "eState_Center" }, { eState_ActiveData, "eState_ActiveData" }, { eState_NonActiveData, "eState_NonActiveData" } };

class IState
{
    private:
    eState currentState;

    public:
    virtual void handleAction ()    = 0;
    virtual void preEnterState ()   = 0;
    virtual void preReleaseState () = 0;
    virtual eState getStateID ()    = 0;
    void setState (eState newState)
    {
        this->currentState = newState;
    }
    eState getState ()
    {
        return this->currentState;
    }
};

#endif