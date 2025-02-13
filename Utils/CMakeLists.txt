cmake_minimum_required(VERSION 3.0)
project(Utils)

set(
    SOURCES
    Button/src/Button.cpp
    GpioRaspberryPi/src/gpioRaspberryPi.cpp
    JsonParser/src/JsonParser.cpp
    LedHandle/src/LedHandle.cpp
    Logger/src/Logger.cpp
    MessageHandler/src/MessageHandler.cpp 
    TimerHandler/src/TimerHandler.cpp
    Utils/src/Utils.cpp
    ApplicationBase/src/ApplicationBase.cpp
    FeatureTimer/src/FeatureTimer.cpp
    InputProcess/Src/InputProcess.cpp
)

link_directories(
    JsonParser/Libs
    JsonParser/Libs/JsonC/src
)

add_library(Utils SHARED ${SOURCES})
add_definitions(-std=c++17)

target_include_directories(
    Utils PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Button/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/GpioRaspberryPi/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/JsonParser/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/JsonParser/Libs/JsonC/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/LedHandle/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/MessageHandler/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/TimerHandler/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../Services/servicemanager
    ${CMAKE_CURRENT_SOURCE_DIR}/../Services/servicemanager/libs/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/../Services/servicemanager/libs/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ApplicationBase/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/FeatureTimer/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/InputProcess/inc
)

target_link_libraries(Utils PUBLIC JsonParser json-c)

install(TARGETS Utils DESTINATION ${CMAKE_SOURCE_DIR})