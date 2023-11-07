#include <iostream>
#include <thread>
#include <string>
#include <future>

class Vehicle
{
public:
    // default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name"))
    {
        std::cout << "Vehicle #" << _id << "Default Constructor called" << std::endl;
    }

    // initializing constructor
    Vehicle(int id, std::string name) : _id{id}, _name(new std::string(name))
    {
        std::cout << "Vehicle #" << _id << "Initializing Constructor called" << std::endl;
    }

    // Overwrite copy-constructor
    Vehicle(Vehicle const &source)
    {
        _id = source._id;
        if (source._name != nullptr)
        {
            _name = new std::string;
            *_name = *source._name;
        }

        std::cout << "Vehicle #" << _id << "Copy Constructor called" << std::endl;
    }

    // Getters
    int getID() { return _id; }
    std::string getName() { return *_name; }

    // Setters
    void setID(int id) { _id = id; }
    void setName(std::string name) { *_name = name; }


private:
    int _id;
    std::string *_name;
};

int main()
{
    // create instances of Vehicle class
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    // launch thread that modifies v0 name
    std::future<void> ftr = std::async([](Vehicle v)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        v.setName("Vehicle 2");
    }, v0);

    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << std::endl;

    return 0;
}