#ifndef INPUTPROCESS_H
#define INPUTPROCESS_H
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
class inputProcess
{
private:
    std::string mGlobalKey;
    std::string mSendDataResult;
    std::string mConnectMQTTResult;
    std::string mReSend;
    std::mutex mMutex;
    bool running;     
    std::thread mInputThread;
    std::function<void(const std::string&)> mCallback;
public:
    inputProcess();
    ~inputProcess();
    void setGlobalKey(const std::string &key);
    std::string getGlobalKey();
    void setSendDataResult(const std::string &key);
    std::string getSendDataResult();
    void setConnectMQTTResult(const std::string &key);
    std::string getConnectMQTTResult();
    void setReSend(const std::string &key);
    std::string getReSend();
    void startInputThread();
    void stopInputThread();  
    static inputProcess *getInstance();
    //void processInput();
    void setCallBackInputProcess(std::function<void(const std::string&)>callBack);
};
#endif