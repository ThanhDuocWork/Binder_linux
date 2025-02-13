cmake_minimum_required(VERSION 3.0)
project(ECallApp)
add_definitions(-Wl,--copy-dt-needed-entries)
set(
    SOURCES
    src/main.cpp
    src/ECallApp.cpp
    src/Adapters/AudioAdapter.cpp
    src/Adapters/HMIAdapter.cpp
    src/Adapters/MqttAdapter.cpp
    src/StateMachine/IDLEState.cpp
    src/StateMachine/CancelTimer.cpp
    src/StateMachine/TransitionTable.cpp
)

include_directories(
    ./inc
    ./inc/Adapters
    ./inc/StateMachine
    ../../Services/AudioSrv/AudioServiceInterface/inc
    ../../Services/AudioSrv/AudioServiceInterface/inc/AudioReceiver
    ../../Services/AudioSrv/AudioServiceInterface/inc/AudioServiceInterface
    ../../Services/HMISrv/HMIMgrSrv/inc
    ../../Services/HMISrv/HMIServiceInterface/inc
    ../../Services/HMISrv/HMIServiceInterface/inc/HMIServiceInterface
    ../../Services/HMISrv/HMIServiceInterface/inc/HMIReceiver
    ../../Services/MqttSrv/MqttMgrSrv/inc
    ../../Services/MqttSrv/MqttServiceInterface/inc
    ../../Services/MqttSrv/MqttServiceInterface/inc/MqttServiceInterface
    ../../Services/MqttSrv/MqttServiceInterface/inc/MqttReceiver
    ../../Services/servicemanager
    ../../Services/servicemanager/libs/utils
    ../../Services/servicemanager/libs/include
    ../../Utils/LedHandle/inc
    ../../Utils/MessageHandler/inc
    ../../Utils/Logger/inc
    ../../Utils/Utils/inc
    ../../Utils/TimerHandler/inc
    ../../Utils/GpioRaspberryPi/inc
    ../../Utils/ServiceDeathRecipient/inc/
    ../../Utils/FeatureTimer/inc/
    ../../Utils/InputProcess/inc
)

link_directories(../../Services/servicemanager/libs)
link_directories(../../Utils)
link_directories(../../Utils/JsonParser/Libs)
link_directories(../../Utils/JsonParser/Libs/JsonC/src)
link_directories(../../Services/HMISrv)
link_directories(../../Services/MqttSrv)
link_directories(../../Services/AudioSrv)

add_executable(ECallApp ${SOURCES})

# Link with all system shared libraries
target_link_libraries(ECallApp PUBLIC pthread binder json-c asound)
# Link with all user shared libraries
target_link_libraries(ECallApp PUBLIC Utils JsonParser HMISrv MqttSrv AudioSrv asound)