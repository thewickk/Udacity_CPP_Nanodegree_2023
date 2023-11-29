#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include <future>

class Vehicle
{
public:
    // Default constructor
    Vehicle() : _id{0}, _name(new std::string("Default name"))
    {
        std::cout << "Vehicle #" << _id << " Default Constructor called" << std::endl;
    }

    // Initializing constructor
    Vehicle(int id, std::string name) : _id{id}, _name{new std::string(name)}
    {
        std::cout << "Vehicle #" << _id << " Initializing Constructor called" << std::endl;
    }

    // Destructor
    ~Vehicle()
    {
        std::cout << "Vehicle #" << _id << " Destructor called" << std::endl;
    }

    // Move Constructor
    Vehicle(Vehicle &&source) : _name(std::move(source._name))
    {
        // move _id to this and reset id in source
        _id = source.getID();
        source.setID(0);

        std::cout << "Vehicle #" << _id << " Move Constructor called" << std::endl;
    }

    // Move Assignment operator
    Vehicle &operator=(Vehicle &&source)
    {
        if (this == &source) { return *this; }

        _name = std::move(source._name);
        _id = source.getID();
        source.setID(0);
        
        return *this;
    }


    // Getters
    int getID() { return _id; }
    std::string getName() { return *_name; }
    
    // Setters
    void setID(int id) { _id = id; }
    void setName(std::string name) { *_name = name; }

private:
    int _id;
    std::unique_ptr<std::string> _name;
};


int main()
{
    // create instances of class Vehicle
    Vehicle v0;    // default constructor
    Vehicle v1(1, "Vehicle 1"); // initializing constructor

    // launch a thread that modifies the Vehicle name
    std::future<void> ftr = std::async([](Vehicle v) {
        v.setName("Vehicle 2");
    },std::move(v0));

    ftr.wait();
    //std::cout << v0.getName() << std::endl; // this will now cause an exception

    return 0;
}