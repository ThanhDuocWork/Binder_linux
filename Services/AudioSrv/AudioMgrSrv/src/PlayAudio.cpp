#include "../inc/PlayAudio.h"

FLAG_AUDIO PlayAudio::openDevice ()
{
    err = snd_pcm_open (&pcm_handle, nameHardware, SND_PCM_STREAM_PLAYBACK, 0);
    if (err < 0)
    {
        cerr << "Can't open sound device: " << snd_strerror (err) << endl;
        return FLAG_AUDIO::ERROR_OPEN_DEVICE;
    }
    return FLAG_AUDIO::OK;
}

FLAG_AUDIO PlayAudio::allocateHardware ()
{
    err = snd_pcm_hw_params_malloc (&hw_params);
    if (err < 0)
    {
        cerr << "Init: cannot allocate hardware parameter structure (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params_any (pcm_handle, hw_params);
    if (err < 0)
    {
        cerr << "Init: cannot allocate hardware parameter structure (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params_set_access (pcm_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED);
    if (err < 0)
    {
        cerr << "Init: cannot set access type (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params_set_format (pcm_handle, hw_params, SND_PCM_FORMAT_S16_LE);
    if (err < 0)
    {
        cerr << "Init: cannot set sample format (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params_set_channels (pcm_handle, hw_params, 2);
    if (err < 0)
    {
        cerr << "Init: cannot set channel count (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params_set_rate_near (pcm_handle, hw_params, &rate, 0);
    if (err < 0)
    {
        cerr << "Init: cannot set sample rate to 44100. (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    err = snd_pcm_hw_params (pcm_handle, hw_params);
    if (err < 0)
    {
        cerr << "Init: cannot set parameters (" << snd_strerror (err) << ")" << endl;
        return FLAG_AUDIO::ERROR_INIT;
    }
    return FLAG_AUDIO::OK;
}

FLAG_AUDIO PlayAudio::openFileWav (const char *wavFile)
{
    wav_file = fopen (wavFile, "r");
    if (!wav_file)
    {
        cerr << "Can't open " << wavFile << " file" << endl;
        return FLAG_AUDIO::ERROR_OPEN_FILE;
    }
    return FLAG_AUDIO::OK;
}

void PlayAudio::playAudio ()
{
    char buffer[4096];
    flagStop = false;
    cout << "Play audio " << endl;
    PlayStateChanged (FLAG_AUDIO::OK_PLAY);

    //----------------------------------------------------------------
    // while (fread(buffer, 1, sizeof(buffer), wav_file) > 0 && flagStop == false) {
    //     err = snd_pcm_writei(pcm_handle, buffer, sizeof(buffer) / 4);
    //     if (err == -EPIPE) {
    //         snd_pcm_prepare(pcm_handle);
    //     } else if (err < 0) {
    //         cerr << "Error when read wav file "<< snd_strerror(err) << endl;
    //         return;
    //     }
    // }
    // fclose(wav_file);
    // PlayStateChanged(FLAG_AUDIO::OK_STOP);
    // snd_pcm_close(pcm_handle);

    //----------------------------------------------------------------

    //----------------------------------------------------------------
    printLog_I ("Play audio success");
    PlayStateChanged (FLAG_AUDIO::OK_STOP);
    //----------------------------------------------------------------

    flagStop = true;
}

void PlayAudio::stopAudio ()
{
    printLog_I ("Stop audio");
    flagStop = true;
}

bool PlayAudio::getFlagStop ()
{
    return flagStop;
}
