#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int RunningProcs()
{
    int running_procs{0};
    std::string line, key, value;
    std::ifstream filestream("/proc/stat");
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            while (linestream >> key >> value)
            {
                if (key == "procs_running")
                {
                    std::cout << linestream << std::endl;
                }
            }
        }
    }

    return running_procs;
}


int main()
{
    int test = RunningProcs();

    return 0;
}