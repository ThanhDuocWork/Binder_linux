#include "ECallApp.h"
#include "AudioAdapter.h"
#include "Logger.h"
#include "MqttAdapter.h"
#include "ParameterDef.h"

ECallApp::ECallApp ()
{
}

ECallApp::~ECallApp ()
{
}

void eventHandlerFunction (std::shared_ptr<EventData> eventData)
{
    if (eventData != nullptr)
    {
        message::ENUM_INTERNAL_MESSAGE messageId = static_cast<message::ENUM_INTERNAL_MESSAGE> (eventData->getMessageId ());
        printLog_I ("Received message: %s", message::messageStringMap.at (messageId).c_str ());
        /* Handle message id */
        switch (messageId)
        {
        case message::ENUM_INTERNAL_MESSAGE::AUDIO_PLAY_STATE_CHANGED:
        {
            /* Parsing and do something with event data */
            std::shared_ptr<AudioEventData> data = std::static_pointer_cast<AudioEventData> (eventData);
            printLog_I ("Audio state: %d", data->mAudioStateChanged);
            break;
        }

        case message::ENUM_INTERNAL_MESSAGE::AUDIO_BINDER_DIED:
        {
            printLog_I ("Register Audio Service after 500ms");
            AudioAdapter::getInstance ()->registerService ();
            break;
        }

        case message::ENUM_INTERNAL_MESSAGE::HMI_EVENT_RECEIVED:
        {
            /* Parsing and do something with event data */
            std::shared_ptr<HMIEventData> data = std::static_pointer_cast<HMIEventData> (eventData);
            printLog_I ("HMI data: %s", data->getData ().c_str ());
            break;
        }
        case message::ENUM_INTERNAL_MESSAGE::HMI_BINDER_DIED:
        {
            printLog_I ("Register HMI Service after 500ms");
            HMIAdapter::getInstance ()->registerService ();
            break;
        }

        case message::ENUM_INTERNAL_MESSAGE::MQTT_EVENT_RECEIVED:
        {
            /* Parsing and do something with event data */
            std::shared_ptr<MqttEventData> data = std::static_pointer_cast<MqttEventData> (eventData);
            printLog_I ("Mqtt topic: %s, data: %s", data->topic.c_str (), data->data.c_str ());
            break;
        }

        case message::ENUM_INTERNAL_MESSAGE::MQTT_BINDER_DIED:
        {
            printLog_I ("Register Mqtt Service after 500ms");
            MqttAdapter::getInstance ()->registerService ();
            break;
        }

        default:
        {
            break;
        }
        }
    }
    else
    {
        printLog_I ("Received a nullptr event");
    }
}

void ECallApp::onCreate ()
{
    // // Create ThreadPool with 2 threads
    printLog_I ("onCreate");
    MessageHandler::getInstance ()->startThreadPool ();
    MessageHandler::getInstance ()->registerEventHandler (eventHandlerFunction);
    /*Register all services*/
    // AudioAdapter::getInstance ()->registerService ();
    // MqttAdapter::getInstance ()->registerService ();
    
    HMIAdapter::getInstance ()->registerService ();
    eState currentState  = eState::eState_IDLE;
    stateMachine = TransitionTable::getInstance ()->getSelectStates (currentState);
    stateMachine->preEnterState ();
}

void ECallApp::onBootCompleted ()
{
    printLog_I ("onBootCompleted");
}

void ECallApp::onDestroy ()
{
    printLog_I ("onDestroy");
}

void ECallApp::onLooper ()
{
    stateMachine = TransitionTable::getInstance ()->getState ();
    if (stateMachine != nullptr)
    {
        stateMachine->handleAction ();
    }
    //EmergencyCall::HMIAdapter::getInstance()->onHMIReceived("abc");
    std::this_thread::sleep_for (std::chrono::seconds (1));
}
