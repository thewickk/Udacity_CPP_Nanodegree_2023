#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

float MemoryUtilization()
{
    double MemTotal, MemFree, MemAvailable, Buffers;
    float MemUtil;
    std::string line;
    std::string key;
    float value;
    std::string kB;
    std::ifstream filestream("/proc/meminfo");
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> key >> value >> kB)
            {
                if (key == "MemTotal:")
                {
                    std::cout << "MemTotal: " << value / 1000 << " mB" << std::endl;
                    MemTotal = value;
                }
                else if (key == "MemFree:")
                {
                    std::cout << "MemFree: " << value / 1000 << " mB" << std::endl;
                    MemFree = value;
                }
                else if (key == "MemAvailable:")
                {
                    std::cout << "MemAvailable: " << value / 1000 << " mB" << std::endl; 
                    MemAvailable = value;
                }
                else if (key == "Buffers:")
                {
                    std::cout << "Buffers: " << value / 1000 << " mB" << std::endl;
                    Buffers = value;
                }
            }
        }
        MemUtil = 1 - (MemAvailable / (MemTotal - Buffers));
        std::cout << "MemUtil/Memtotal: " <<  (MemTotal / MemUtil) * 100 << std::endl;
        std::cout << "MemUtil: " << MemUtil << std::endl;
    }
    return MemUtil;
}

int main()
{
    float test = MemoryUtilization();
    return 0;
}