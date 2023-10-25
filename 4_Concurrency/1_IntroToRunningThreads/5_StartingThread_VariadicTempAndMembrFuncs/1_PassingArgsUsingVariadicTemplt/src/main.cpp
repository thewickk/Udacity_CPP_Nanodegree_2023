#include <iostream>
#include <thread>
#include <string>

void printID(int id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "ID: " << id << std::endl;
}

void printIDandName(int id, std::string name)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID: " << id << " Name: " << name << std::endl;
}

int main()
{
    int id = 0;

    // starting threads using variadic templates
    std::thread t1(printID, id);
    std::thread t2(printIDandName, ++id, "MyString");
    //std::thread t3(printIDandName, ++id); // compiler error: requires args in function signature

    t1.join();
    t2.join();

    return 0;
}