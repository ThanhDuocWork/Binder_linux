#ifndef PLAY_AUDIO_H_
#define PLAY_AUDIO_H_

#include <alsa/asoundlib.h>
#include <iostream>

#include "Logger.h"

using namespace std;

enum class FLAG_AUDIO : uint32_t
{
    OK = 0,
    OK_PLAY,
    OK_STOP,
    ERROR_INIT,
    ERROR_OPEN_DEVICE,
    ERROR_OPEN_FILE,
    ERROR_READ_FILE,
};

class PlayAudio
{
private:
    snd_pcm_t *pcm_handle;
    const char *nameHardware = "hw:1,0";
    int err;
    snd_pcm_hw_params_t *hw_params;
    unsigned int rate = 44100;
    FILE *wav_file;
    char buffer[4096];
    bool flagStop = false;
    virtual void PlayStateChanged(FLAG_AUDIO stateCurrent) = 0;

public:
    void stopAudio();
    void playAudio();
    bool getFlagStop();
    FLAG_AUDIO openFileWav(const char *name);
    FLAG_AUDIO openDevice();
    FLAG_AUDIO allocateHardware();
};
#endif