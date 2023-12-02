#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <algorithm>
#include <mutex>

double result;
std::mutex _mutex;

void printResult(int denom)
{
    std::cout << "for denom = " << denom << ", the result is " << result << std::endl;
}

void divideByNumber(double num, double denom)
{
    //_mutex.lock(); //deadlock
    try
    {
        // divide num by denom but throw an exception if division by zero is attempted

        if (denom != 0)
        {
            _mutex.lock();
            result = num / denom;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            printResult(denom);
            _mutex.unlock();
        }
        else
        {
            throw std::invalid_argument("Exception from thread: Division by zero!");
        }
    }
    catch (const std::invalid_argument& e)
    {
        // notify the user about the exception and return
        std::cerr << e.what() << '\n';
        return;
    }
    //_mutex.unlock(); //deadlock
    
}

int main()
{
    // create a number of threads which execute the function "divideByNumber" with varying parameters
    std::vector<std::future<void>> futures;
    for (double i = -5; i <= +5; ++i)
    {
        futures.emplace_back(std::async(std::launch::async, divideByNumber, 50.0, i));
    }

    // wait for the results
    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr)
    {
        ftr.wait();
    });

    return 0;
}