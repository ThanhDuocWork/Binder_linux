package MqttReceiver;

interface MqttReceiver
{
    void onMqttReceived(String topic, String data);
}