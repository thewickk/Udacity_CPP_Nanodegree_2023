#include <iostream>
#include <thread>
#include <memory>
#include <string>

class Vehicle
{
public:
    Vehicle() : _id{0}, _name{"empty"} {}
    void addID(int id) {_id = id; }
    void setName(std::string name) { _name = name; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }
    void printName()
    {
        std::cout << "Vehicle Name=" << _name << std::endl;
    }

private:
    int _id;
    std::string _name;
};

int main()
{
    // create thread
    Vehicle v1, v2;
    // pass by value, no change to v1
    std::thread t1 = std::thread(&Vehicle::addID, v1, 1); // call member func on obj v
    // pass by reference, will change value of v2
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2);

    // wait for thread to finish
    t1.join();
    t2.join();

    // pring Vehicle id
    v1.printID();
    v2.printID();

    // Using heap allocated memory to ensure object lifetime
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 1);
    std::thread t3 = std::thread(&Vehicle::setName, v, "Goose");

    t.join();
    t3.join();
    v->printID();
    v->printName();

    return 0;
}