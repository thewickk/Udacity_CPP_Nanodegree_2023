#include <iostream>
#include <memory>

class MyClass
{
public:
    ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> shared1(new MyClass);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    {
        std::shared_ptr<MyClass> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    }
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    return 0;
}