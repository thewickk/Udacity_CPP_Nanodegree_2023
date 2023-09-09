#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

long Uptime()
{
    long procTime{};
    std::string line;
    std::ifstream filestream("/proc/uptime");
    if (filestream.is_open())
    {
        std::getline(filestream, line);
        std::istringstream lineStream(line);
        lineStream >> procTime;
    }
    return procTime;
}

std::string ElapsedTime(long seconds) 
{ 
    int hours = seconds / 3600;         // 3600 seconds in an hour
    int min = ((seconds % 3600) / 60);  // 
    int sec = seconds % 60;
    std::stringstream formattedTime;
    formattedTime << std::to_string(hours) << ":" << std::setw(2) << std::setfill('0') << std::to_string(min) << ":" << std::setw(2) << std::setfill('0') << std::to_string(sec);

    return formattedTime.str(); 
}

int main()
{
    long test = Uptime();
    std::cout << "test: " << test << std::endl;
    std::string timestring = ElapsedTime(Uptime());
    std::cout << timestring << std::endl;
    return 0;
}