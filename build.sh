#!/bin/sh
# Define color
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Status of environment
ENV_STATE="1"
#Default variables
OUTPUT_DIR="output/"
PACKAGE_DIR="output/package/"
N_CPU=`nproc`
BUILD_MODE="debug"
BUILD_ARGS=""
APP_NAME=""
FORCE_BUILD="0"
CUSTOM_ARG_LIST=""
#===================Define local function===========================================
println()
{
    echo $1$2${NC}
}

check_tool()
{
    println $NC "Checking $1"
    STATE=`$1 --help`
    if ! [ "$STATE" = '' ]; then
    println $GREEN "-> Installed"
    else
        println  $RED "-> Not Installed"
        ENV_STATE="0"
    fi
}

check_library()
{
    println $NC "Checking library $1"
    STATE=`ldconfig -p | grep $1`
    echo $STATE
    if ! [ "$STATE" = '' ]; then
        println $GREEN "-> Installed"
    else
        println  $RED "-> Not Installed"
        ENV_STATE='false'
    fi
}

print_help()
{
    println $NC "./build.sh <OPTIONS>"
    println $NC "OPTIONS:"
    println $NC "\t-release: Build application in release mode. Default is debug mode"
    println $NC "\t-debug: Build application in debug mode"
    println $NC "\t-app <app_name>: Build specific application"
    println $NC "\t-f: Force build without checking environment"
    println $NC "\t-arg <argument list>: Custom argument list"
}

check_environment()
{
    # Checking installed tool
    println $NC "Checking environment..."
    check_tool "cmake"
    check_tool "make"
    check_tool "gcc"
    check_tool "g++"

    # Checking installed libraries
    check_library "libasound"

    #Checking kernel header
    println $NC "Check kernel header version $(uname -r)"
    if [ -d /lib/modules/$(uname -r)/ ]; then
        println $GREEN "-> Installed"
    else
        println  $RED "-> Not Installed"
        ENV_STATE="0"
    fi

    # Final result, do action?
    if ! [ $ENV_STATE = "1" ];then
        return 1;
    fi
    return 0;
}
#==================================================================================

#====================================MAIN==========================================
while [ 1 -le $# ]
do
    if [ $1 = "-release" ];then
        BUILD_MODE="release"
        shift 1;
    elif [ $1 = "-debug" ];then
        BUILD_MODE="debug"
        shift 1;
    elif [ $1 = "-app" ];then
        shift 1;
        APP_NAME=$1
        shift 1;
    elif [ $1 = "-arg" ];then
        shift 1;
        CUSTOM_ARG_LIST=$1
        shift 1;
    elif [ $1 = "-f" ];then
        FORCE_BUILD="1"
        shift 1;
    elif [ $1 = "-h" ];then
        print_help
        exit 0
    else
        println  $RED "Unknown option: '$1'"
        print_help
        exit 1
    fi
done

# Checking force build
if ! [ $FORCE_BUILD = "1" ];then
    check_environment
    STATE=$?
    if [ $STATE = 1 ];then
        println $RED "Environment is not enough for building software, please check"
        exit 1
    fi
fi

# Checking build mode
if [ $BUILD_MODE = "debug" ];then
    BUILD_ARGS="-std=c++0x -Werror -g -D_STD_LOG_"
elif [ $BUILD_MODE = "release" ];then
    BUILD_ARGS="-std=stdc++17 -Werror"
fi

rm -rf $OUTPUT_DIR
if [ ! -d $OUTPUT_DIR ];then
    println $GREEN "Creating output directory at $OUTPUT_DIR"
    mkdir -p $OUTPUT_DIR
fi

#=================================RUN CODE GEN BEFORE BUILDING=====================
println $NC "Code generating begin"
CUR_PWD=`pwd`
cd Tools/Commander/src/
python3 gen.py
cd $CUR_PWD
#Generate source code for Audio Service
cd Services/AudioSrv/AudioServiceInterface
mkdir -p inc
make
cd $CUR_PWD
#Generate source code for HMI Service
cd Services/HMISrv/HMIServiceInterface
mkdir -p inc
make
cd $CUR_PWD
#Generate source code for MQTT Service
cd Services/MqttSrv/MqttServiceInterface
mkdir -p inc
make
cd $CUR_PWD
println $NC "Code generating end"
#==================================================================================
println $NC "=====================Build information====================="
println $NC "BUILD_MODE: $BUILD_MODE"
println $NC "APP_NAME: $APP_NAME"
println $NC "FORCE_BUILD: $FORCE_BUILD"
println $NC "CUSTOM_ARG_LIST: $CUSTOM_ARG_LIST"
println $NC "BUILD_ARGS: $BUILD_ARGS"
println $NC "==========================================================="
#=================================BUILD============================================
if [ "$APP_NAME" = "" ];then
    println $GREEN "Build all applications"
    cd $OUTPUT_DIR
    cmake .. -DCMAKE_CXX_FLAGS="$BUILD_ARGS" $CUSTOM_ARG_LIST
    make -j$N_CPU
else
    println $GREEN "Build $APP_NAME"
    cd $OUTPUT_DIR
    cmake .. -DCMAKE_CXX_FLAGS="$BUILD_ARGS" $CUSTOM_ARG_LIST
    make $APP_NAME -j$N_CPU
fi
#Return current directory
cd $CUR_PWD
#==================================================================================
#=================================GENERATE PACKAGES================================
println $GREEN "Generating packages"
if [ ! -d $PACKAGE_DIR ];then
    println $GREEN "Creating output directory at $PACKAGE_DIR"
    mkdir -p $PACKAGE_DIR
fi
println $GREEN "Copying files to $PACKAGE_DIR"
cp ${OUTPUT_DIR}Apps/EcallApp/ECallApp $PACKAGE_DIR
cp ${OUTPUT_DIR}Services/AudioSrv/AudioMgrSrv/AudioMgrSrv $PACKAGE_DIR
cp ${OUTPUT_DIR}Services/AudioSrv/AudioMgrSrv/AudioMgrSrv $PACKAGE_DIR
cp ${OUTPUT_DIR}Services/HMISrv/HMIMgrSrv/HMIMgrSrv $PACKAGE_DIR
cp ${OUTPUT_DIR}Services/MqttSrv/MqttMgrSrv/MqttMgrSrv $PACKAGE_DIR
#==================================================================================