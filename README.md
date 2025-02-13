# GUIDE

## 1. Build source
   - In "~/eCall" folder, use command:
     `./build.sh `

   - If all libs already exist, the source is ready to build

### For Tools/Commander using when testing: 
   - Before building, you need to run python file ~/eCall/Tools/Commander/src/gen.py to auto-gen file ~/eCall/Tools/Commander/src/CMakeLists.txt 
     `python3 gen.py` 
   - In folder "~/eCall/Tools/Commander" have also file Makefile and CMakeList.txt, use command: 
     `cd ~/eCall/Tools/Commander`
     `mkdir build`                          
     `cd build` 
     `cmake ..`                              
     `make` 

## 2. How to run source code 

   - Before running the executable file in step 1. How to build, need to run servicemanager: 
        `cd ~/eCall/Services/servicemanager` 
        `make`
        `./project.sh insmod` 
        `sudo ./servicemanager` 
 
   - For EcallApp, in the terminal screen during build, use the command:
        `cd ~/ecall/output/Apps/EcallApp`
        `sudo ./ECallApp` 

#### 1. Audio Service
   - For MqttMgrSrv, in the terminal screen during build, use the command:
        `cd ~/ecall/output/Services/AudioSrv/AudioMgrSrv`
        `sudo ./MqttMgrSrv` 

   - For Tools/Commander, currently, I only code a few commands to test EcallApp's Audio (Use for testing only)
        `sudo ./commander AudioMgrSrv playAudio ~/eCall/Apps/EcallApp/sample.wav` 
        `sudo ./commander AudioMgrSrv stopAuido` 
        `sudo ./commander AudioMgrSrv playAudio help` 
        `sudo ./commander AudioMgrSrv stopAuido help` 
      
#### 2. MQTT Service
   - For MqttMgrSrv, in the terminal screen during build, use the command:
        `cd ~/ecall/output/Services/MqttSrv/MqttMgrSrv`
        `sudo ./MqttMgrSrv`  

#### 3. HMI Service
   - For HMIMgnSrv, in the terminal screen during build, use the command:
        `cd ~/ecall/output/Services/HMISrv/HMIMgnSrv`
        `sudo ./HMIMgnSrv`                     

## 3. How to use aidl to generate source code of stub-proxy of IPC Binder 
   - In "~/eCall/Services/AudioSrv/AudioServiceInterface/aidl" folder, there is a Makefile to generate source of stub-proxy of IPC Binder, use command:
        *Gen AudioServiceInterface*
        `make 1_aidl-cpp` 
        *Gen AudioReceiver*
        `make 2_aidl-cpp`

   - Similar to "~/eCall/Services/HMI/HMIServiceInterface/aidl" and "~/eCall/Services/MQTTSrv/MQTTServiceInterface/aidl" 

Link refer: 

[AIDL Format](https://android.googlesource.com/platform/system/tools/aidl/+/brillo-m10-dev/docs/aidl-cpp.md)

[aidl-cpp](https://manpages.ubuntu.com/manpages/focal/man1/aidl-cpp.1.html) 

## 4. Not completed items
### 1. Audio 
   - Events from callback have not yet been processed 
   - PlayAudio cannot choose driver to play 
### 2. HMI 
   - No events have been created for the HMI yet 
### 3. MQTTSrv 
   - No events have been created for the MQTTSrv yet 

## 5. Note
*Note: install tilix, used to divide the terminal screen for easy*
`sudo apt update`
`sudo apt installl tilix`
[Link refer](https://www.geeksforgeeks.org/how-to-install-tilix-terminal-emulator-in-ubuntu-fedora-arch-linux/)

### For Services/AudioSrv (sample for AudioMgrSrv ): 
*Note: intsall libasound2-dev if not install after*
`sudo apt-get install -y libasound2-dev`

### For Services/MQTTSrv:
#### Build mosquitto 2.0.18 
[mosquitto 2.0.18](https://github.com/eclipse/mosquitto/tree/v2.0.18)

`git clone https://github.com/eclipse/mosquitto.git`
`cd mosquitto`
`make WITH_CJSON=no WITH_DOCS=no`
`cd src`
`sudo make install`