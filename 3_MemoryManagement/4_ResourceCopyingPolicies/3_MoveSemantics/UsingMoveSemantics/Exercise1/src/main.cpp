/*
* Exercise 1: Passing data between functions without move semantics
*/
#include <iostream>
#include <vector>
#include <cmath>

// pass back by pointer (old C++)
const int array_size = 1e6; // determines size of the random number array
std::vector<int> *RandomNumbers1()
{
    // allocate memory on the heap...
    std::vector<int> *random_numbers = new std::vector<int>[array_size]; 
    for (int i = 0; i < array_size; i++)
    {
        int b = rand();
        (*random_numbers).push_back(b); // ...and fill it with random numbers
    }
    return random_numbers; // return pointer to heap memory
}

// pass back by reference (old C++)
void RandomNumbers2(std::vector<int> &random_numbers)
{
    random_numbers.resize(array_size); // expand vector to desired size
    for (int i = 0; i < array_size; i++)
    {
        random_numbers[i] = rand();
    }
}

int main()
{
    /* EXERCISE 1-1: Get access to random data using a returned pointer from
       function RandomNumbers1 and make sure that there are no memory leaks

       Store the data in a suitable variable named 'random_numbers_1' and 
       free the associated memory immediately afterwards
    */
    std::vector<int> *random_numbers_1 = RandomNumbers1();
    delete[] random_numbers_1;

    /* EXERCISE 1-2: Get access to data using pass-by-reference
       
       Store the data in a suitable variable named 'random_numbers_2'
    */
     std::vector<int> random_numbers_2;
     RandomNumbers2(random_numbers_2);
     std::cout << "Size: " << random_numbers_2.size() << std::endl;
     for (int i = 0; i < 5; i++)
     {
        std::cout << "random_numbers_2[" << i << "]: " << random_numbers_2[i] << std::endl;
     }

    return 0;
}