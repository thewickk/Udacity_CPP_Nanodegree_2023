#include <iostream>
#include <thread>

/*
Please create a new function called threadFunctionOdd that outputs the string "Odd threadn". 
Then write a for-loop that starts 6 threads and immediately detaches them. 
Based on wether the increment variable is even or odd, you should pass the respective function to the thread.
*/

void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

/* Student Task START */
void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thead\n";
}

/* Student Task END */

int main()
{
    /* Student Task START */
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            std::thread t(threadFunctionEven);
            t.detach();
        }
        else
        {
            std::thread t(threadFunctionOdd);
            t.detach();
        }
    }

    /* Student Task END */

    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}