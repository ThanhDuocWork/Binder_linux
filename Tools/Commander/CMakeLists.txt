cmake_minimum_required(VERSION 3.0)
project(Commander VERSION 1.0.0 LANGUAGES C CXX)

set(SOURCES
    src/main.cpp 
    src/CommanderHelper.cpp
    ../../Apps/EcallApp/src/Adapters/AudioAdapter.cpp
    ../../Services/AudioSrv/AudioServiceInterface/src/AudioServiceInterface.cpp
    ../../Services/AudioSrv/AudioServiceInterface/src/AudioReceiver.cpp
    ../../Services/MqttSrv/MqttServiceInterface/src/MqttServiceInterface.cpp
    ../../Utils/MessageHandler/src/MessageHandler.cpp
    ../../Services/servicemanager/libs/binder/Status.cpp
    ../../Services/servicemanager/libs/binder/Parcel.cpp
    ../../Services/AudioSrv/AudioMgrSrv/src/AudioMgrSrv.cpp
    ../../Services/AudioSrv/AudioMgrSrv/src/PlayAudio.cpp
    ../../Utils/Logger/src/Logger.cpp
    ../../Utils/Utils/src/Utils.cpp
    ../../Utils/InputProcess/Src/InputProcess.cpp
)

include_directories(
    ./inc
    ../../Apps/EcallApp/inc
    ../../Apps/EcallApp/inc/Adapters
    ../../Utils/Logger
    ../../Services/AudioSrv/AudioMgrSrv/inc
    ../../Services/AudioSrv/AudioServiceInterface/inc
    ../../Services/AudioSrv/AudioServiceInterface/inc/AudioReceiver
    ../../Services/AudioSrv/AudioServiceInterface/inc/AudioServiceInterface
    ../../Services/HMISrv/HMIMgrSrv/inc
    ../../Services/HMISrv/HMISrvInterface/inc
    ../../Services/HMISrv/HMISrvInterface/inc/HMISrvInterface
    ../../Services/HMISrv/HMISrvInterface/inc/HMISrvInterface/inc
    ../../Services/HMISrv/HMISrvInterface/inc/HMISrvInterface/inc/HMIReceiver
    ../../Services/MqttSrv/MqttServiceInterface/inc
    ../../Services/MqttSrv/MqttServiceInterface/inc/MqttServiceInterface
    ../../Services/servicemanager
    ../../Services/servicemanager/libs/utils
    ../../Services/servicemanager/libs/include
    ../../Utils/LedHandle/inc
    ../../Utils/MessageHandler/inc
    ../../Utils/Logger/inc
    ../../Utils/Utils/inc
    ../../Utils/TimerHandler/inc
    ../../Utils/GpioRaspberryPi/inc
    ../../Services/MqttSrv/MqttMgrSrv/inc
    ../../Services/HMISrv/HMISrvInterface/inc/HMIReceiver
    ../../Utils/ServiceDeathRecipient/inc/
    ../../Utils/InputProcess/inc

)

include(src/CMakeLists.txt)

link_directories(
    ../../Services/servicemanager/libs
    ../../Utils
    ../../Utils/JsonParser/Libs
    ../../Utils/JsonParser/Libs/JsonC/src
    )

add_executable(commander ${SOURCES} ${SOURCE_SCRIPTS})

target_link_libraries(commander PRIVATE pthread asound binder Utils) 
