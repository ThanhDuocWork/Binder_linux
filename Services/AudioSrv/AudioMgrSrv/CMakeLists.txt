cmake_minimum_required(VERSION 3.0)
project(AudioMgrSrv)

set(
    SOURCES
    src/main.cpp
    src/AudioMgrSrv.cpp
    src/PlayAudio.cpp
    ../AudioServiceInterface/src/AudioServiceInterface.cpp
    ../../servicemanager/libs/binder/Status.cpp
    ../../servicemanager/libs/binder/Parcel.cpp
    ../AudioServiceInterface/src/AudioReceiver.cpp
)

include_directories(
    ./inc
    ../../servicemanager
    ../../servicemanager/libs/include
    ../../servicemanager/libs/utils
    ../../servicemanager/libs/include/binder
    ../../../Utils/Logger/inc
    ../../../Utils/LedHandle/inc
    ../../../Utils/MessageHandler/inc
    ../AudioServiceInterface/inc
    ../AudioServiceInterface/inc/AudioReceiver
    ../AudioServiceInterface/inc/AudioServiceInterface
)

link_directories(../../servicemanager/libs)
link_directories(../../../Utils)
link_directories(../../../Utils/JsonParser/Libs)
link_directories(../../../Utils/JsonParser/Libs/JsonC/src)

add_library(AudioSrv SHARED ${SOURCES})

add_executable(AudioMgrSrv ${SOURCES})

target_link_libraries(AudioMgrSrv PRIVATE binder asound pthread Utils)