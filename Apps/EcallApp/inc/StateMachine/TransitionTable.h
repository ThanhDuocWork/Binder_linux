#ifndef TRANSITONTABLE_H
#define TRANSITONTABLE_H
#include "IState.h"
#include "IDLEState.h"
#include "CancelTimerState.h"
#include <map>
#include<vector>
#include "Logger.h"
class TransitionTable 
{
private:
    IState *stateMachine;
    std::map<eState, std::vector<IState*>> stateMap;
    std::map<eState, IState*>eMap;
public:
    TransitionTable();
    ~TransitionTable();
    IState* setState(eState currentState,eState newState);
    IState *getState();
    IState *getSelectStates(eState currentState);
    const std::map<eState, std::vector<IState*>>& getStateTransitionTable() const;
    static TransitionTable* getInstance();
};
#endif