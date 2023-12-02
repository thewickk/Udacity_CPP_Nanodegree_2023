#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1, mutex2;

void ThreadA()
{
    // Creates deadlock problem
    mutex2.lock();
    std::cout << "Thead A" << std::endl;
    mutex1.lock();
    mutex2.unlock();
    mutex1.unlock();
}

void ThreadB()
{
    // Creates deadlock problem
    mutex1.lock();
    std::cout << "Thread B" << std::endl;
    mutex2.lock();
    mutex1.unlock();
    mutex2.unlock();
}

void ExecuteThreads()
{
    std::thread t1( ThreadA );
    std::thread t2( ThreadB );

    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;
}

int main()
{
    ExecuteThreads();

    return 0;
}


// Deadlock solution:
/*
number all resources and require that processes request resources only in strictly 
increasing (or decreasing) order

void ThreadA()
{
    // Solves deadlock problem
    mutex1.lock();
    std::cout << "Thread A" << std::endl;
    mutex2.lock();
    mutex2.unlock();
    mutex1.unlock();
}

void ThreadB()
{
    // Solves deadlock problem
    mutex1.lock();
    std::cout << "Thread B" << std::endl;
    mutex2.lock();
    mutex1.unlock();
    mutex2.unlock();
}

*/