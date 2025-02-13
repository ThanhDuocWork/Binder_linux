package AudioServiceInterface;

interface AudioServiceInterface {
    int PlayAudio(String filePath);
    int StopAudio();
    void callBack();
    void registerReceiver(in IBinder binder);
}