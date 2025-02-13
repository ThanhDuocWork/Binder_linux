cmake_minimum_required(VERSION 3.0)
project(MqttMgrSrv)

set(
    SOURCES
    src/main.cpp
    src/MqttMgrSrv.cpp
    ../MqttServiceInterface/src/MqttServiceInterface.cpp
    ../../../Utils/Logger/src/Logger.cpp
    ../../../Utils/Utils/src/Utils.cpp
    ../../servicemanager/libs/binder/Status.cpp
    ../../servicemanager/libs/binder/Parcel.cpp
    ../MqttServiceInterface/src/MqttReceiver.cpp
)

include_directories(
    ./inc
    ../../servicemanager
    ../../servicemanager/libs/include
    ../../servicemanager/libs/utils
    ../../servicemanager/libs/include/binder
    ../../../Utils/Logger/inc
    ../../../Utils/Utils/inc
    ../MqttServiceInterface/inc
    ../MqttServiceInterface/inc/MqttServiceInterface
)

link_directories(../../servicemanager/libs)
link_directories(../../../Utils)
link_directories(../../../Utils/JsonParser/Libs)
link_directories(../../../Utils/JsonParser/Libs/JsonC/src)

add_library(MqttSrv SHARED ${SOURCES})

add_executable(MqttMgrSrv ${SOURCES})

target_link_libraries(MqttMgrSrv PRIVATE binder pthread)