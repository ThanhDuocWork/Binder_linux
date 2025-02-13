cmake_minimum_required(VERSION 3.0)
project(HMIMgrSrv)

set(
    SOURCES
    src/main.cpp
    src/HMIMgrSrv.cpp
    ../HMIServiceInterface/src/HMIServiceInterface.cpp
    ../../../Utils/Logger/src/Logger.cpp
    ../../../Utils/Utils/src/Utils.cpp
    ../../../Utils/InputProcess/Src/InputProcess.cpp
    ../../servicemanager/libs/binder/Status.cpp
    ../../servicemanager/libs/binder/Parcel.cpp
    ../HMIServiceInterface/src/HMIReceiver.cpp
)

include_directories(
    ./inc
    ../../servicemanager
    ../../servicemanager/libs/include
    ../../servicemanager/libs/utils
    ../../servicemanager/libs/include/binder
    ../../../Utils/Logger/inc
    ../../../Utils/Utils/inc
    ../../../Utils/InputProcess/inc
    ../HMIServiceInterface/inc
    ../HMIServiceInterface/inc/HMIServiceInterface
    ../HMIServiceInterface/inc/HMIReceiver
    ../HMIServiceInterface/inc/HMIServiceInterface
)

link_directories(../../servicemanager/libs)
link_directories(../../../Utils)
link_directories(../../../Utils/JsonParser/Libs)
link_directories(../../../Utils/JsonParser/Libs/JsonC/src)

add_library(HMISrv SHARED ${SOURCES})

add_executable(HMIMgrSrv ${SOURCES})

target_link_libraries(HMIMgrSrv PRIVATE binder pthread)