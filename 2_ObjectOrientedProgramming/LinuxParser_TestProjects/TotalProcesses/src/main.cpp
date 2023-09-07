#include <iostream>
#include <fstream>
#include <sstream>

int TotalProcesses()
{
    std::string line;
    std::string key;
    int processes;
    std::ifstream filestream("/proc/stat");
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> key >> processes)
            {
                if (key == "processes") return processes;
            }
        }
    }
    return -1;
}


int main()
{
    int test = TotalProcesses();
    std::cout << "Test: " << test << std::endl;
    return 0;
}