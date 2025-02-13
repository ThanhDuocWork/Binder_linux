package HMIServiceInterface;

interface HMIServiceInterface
{
    void requestLedPattern(String ledPattern);
    void registerReceiver(in IBinder binder);
}