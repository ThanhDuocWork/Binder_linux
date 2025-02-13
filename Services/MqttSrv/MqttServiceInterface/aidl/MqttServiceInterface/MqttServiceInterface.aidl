package MqttServiceInterface;

interface MqttServiceInterface
{
    void Connect(String broker);
    void Disconnect();
    void Subscribe(String topic);
    void Publish(String topic, String payload);
    void registerReceiver(in IBinder binder);
}