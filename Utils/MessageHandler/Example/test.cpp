#include "Inc/MessageHandler.h"


void _msg(std::shared_ptr<EventData> event);

int main() {

    MessageHandler threadPool(1);
    threadPool.registerEventHandler([](std::shared_ptr<EventData> event){
        if(event != nullptr)
        {
            printf("HELLO ");
            std::cout << event->getMessageId() << std::endl;
        }
    });
    threadPool.startThreadPool();
    std::shared_ptr<EventData> eventData = std::make_shared<EventData>(2);
    threadPool.addEventData(eventData);

    for (size_t i = 0; i < 1; i++)
    {
        std::cout << "Start loop" << std::endl;
        std::cout << "End loop" << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    threadPool.stopThreadPool();

    return 0;
}

void _msg(std::shared_ptr<EventData> event)
{
    if(event != nullptr)
    {
        std::cout << event->getMessageId() << std::endl;
    }
}
