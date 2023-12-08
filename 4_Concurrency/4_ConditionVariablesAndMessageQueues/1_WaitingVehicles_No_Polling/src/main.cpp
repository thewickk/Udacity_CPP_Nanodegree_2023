#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include <algorithm>

class Vehicle
{
public:
    Vehicle(int id) : _id{id} {};
    int getID() { return _id; }
private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}
    
    void printIDs()
    {
        std::lock_guard<std::mutex> myLock(_mutex);
        for (auto &v : _vehicles)
        {
            std::cout << " Vehicle #" << v.getID() << " is now waiting in the queue" << std::endl;
        }
    }

    void pushBack(Vehicle &&v)
    {
        std::lock_guard<std::mutex> uLock(_mutex);
        std::cout << " Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(std::move(v));

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

private:
  std::vector<Vehicle> _vehicles;
  std::mutex _mutex;  
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // create a new Vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }
    
    for (auto &ftr : futures) ftr.wait();
    std::cout << "Collecting resutls..." << std::endl;
    queue->printIDs();

    return 0;
}