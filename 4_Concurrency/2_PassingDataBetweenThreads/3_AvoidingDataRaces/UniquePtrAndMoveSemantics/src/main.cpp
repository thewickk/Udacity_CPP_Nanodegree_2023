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

    // Copy Constructor
    Vehicle(const Vehicle &source)
    {
        _id = source._id;
        if (source._name != nullptr)
        {
            _name = new std::string;
            *_name = *source._name;
        }

        std::cout << "Vehicle #" << _id << " Copy Constructor called" << std::endl;
    }

    // Copy Assignment Operator
    Vehicle &operator=(const Vehicle &source)
    {
        if (this == &source) { return *this; }

        delete _name;
        _name = new std::string;
        *_name = *source._name;
        _id = source._id;

        std::cout << "Vehicle #" << _id << " Copy Assignment called" << std::endl;

        return *this;
    }

    // Move Constructor
    Vehicle(Vehicle &&source)
    {
        _id = source.getID();
        _name = new std::string(source.getName());

        source.setID(0);
        source.setName("Default name");

        std::cout << "Vehicle #" << _id << " Move Constructor called" << std::endl;
    }

    // Move Assignment operator
    Vehicle &operator=(Vehicle &&source)
    {
        if (this == &source) { return *this; }

        delete _name;
        _name = new std::string;
        *_name = *source._name;
        _id = source._id;

        source.setID(0);
        source.setName("Default name");

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
    std::cout << v0.getName() << std::endl; // this will now cause an exception

    return 0;
}