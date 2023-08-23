#include <iostream>
#include <limits>
#include <sstream>

int main()
{
    float start_x, start_y, end_x, end_y;
    std::string line;
    std::cout << "Enter your floats: ";
    while(std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if ((ss >> start_x) && (ss >> start_y) && (ss >> end_x) && (ss >> end_y) && ss.eof())
        {
            std::cout << "Thank you processing your input...\n";
            break;
        }
        else
        {
            std::cout << "Please enter valid values: ";
        }
    }
    std::cout << "You entered: " << start_x << ", " << start_y << ", " << end_x << ", " << end_y << std::endl;
    float min_dist = std::numeric_limits<float>::max();

    std::cout << "Min dist: " << min_dist << std::endl;


    return 0;
}