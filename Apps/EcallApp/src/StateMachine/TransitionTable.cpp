#include "TransitionTable.h"
TransitionTable::TransitionTable()
{
    // initial IDLE state
    stateMachine = IDLEState::getInstance();
    stateMap = {
        {eState::eState_IDLE, {CancelTimerState::getInstance()}}};
    eMap = {
        {eState::eState_IDLE, {IDLEState::getInstance()}},
        {eState::eState_CancelTimer, {CancelTimerState::getInstance()}}};
}
TransitionTable::~TransitionTable()
{
}
TransitionTable *TransitionTable::getInstance()
{
    static std::shared_ptr<TransitionTable> instance;
    if (instance == nullptr)
    {
        instance = std::make_shared<TransitionTable>();
    }
    return instance.get();
}
IState *TransitionTable::getState()
{
    return stateMachine;
}
IState *TransitionTable::getSelectStates(eState state)
{
    auto states = eMap.find(state);
    if (states != eMap.end())
    {
        return states->second;
    }
    else
    {
        printLog_I("return getSelectStates nullptr");
        return nullptr;
    }
}
const std::map<eState, std::vector<IState *>> &TransitionTable::getStateTransitionTable() const
{
    return stateMap;
}
IState *TransitionTable::setState(eState currentState, eState newState)
{
    stateMachine = getSelectStates(currentState);
    if (stateMachine != nullptr)
    {
        currentState = stateMachine->getStateID();
        auto states = stateMap.at(currentState);
        for (auto mState : states)
        {
            if (newState == mState->getStateID())
            {
                stateMachine->preReleaseState();
                stateMachine = mState;
                stateMachine->preEnterState();
                return stateMachine;
            }
        }
        printLog_I("State not found");
    }
    else
    {
        printLog_I("null stateMachine setState");
    }
}