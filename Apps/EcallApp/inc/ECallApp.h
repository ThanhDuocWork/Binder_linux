#include <thread>
#include <unistd.h>
#include "ApplicationBase.h"
#include "MessageHandler.h"
#include "AudioAdapter.h"
#include "HMIAdapter.h"
#include "IAudioReceiver.h"
#include "TransitionTable.h"
#include "IDLEState.h"
using namespace EmergencyCall;
class ECallApp : public ApplicationBase
{
public:
    ECallApp();
    ~ECallApp();
    void onCreate() override;
    void onBootCompleted() override;
    void onDestroy() override;
    void onLooper() override;

private:
    /* data */
    IState *stateMachine;
};
