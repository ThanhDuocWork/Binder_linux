#include "../Inc/TimerHandler.h" 

void task1() {
    std::cout << "Task 1 executed" << std::endl;
}

void task2() {
    std::cout << "Task 2 executed" << std::endl;
}

int main()
{
    TimerHandler timer1(task1, 5000);
    TimerHandler timer2(task2, 10000);

    timer1.start(); 
    timer2.start();

    std::this_thread::sleep_for(std::chrono::seconds(8));

    timer1.stop(); 
    timer2.stop(); 

    timer1.start(); 
    timer2.start();

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}