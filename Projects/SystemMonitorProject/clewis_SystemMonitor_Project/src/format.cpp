#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

std::string Format::ElapsedTime(long seconds) 
{ 
    const int sec_in_day{86400};
    const int sec_in_hour{3600};
    const int sec_in_min{60};
    const int second{1};

    int hours = seconds / sec_in_hour;
    int minutes = ((seconds % sec_in_day) % sec_in_hour) / sec_in_min;
    int sec = (((seconds % sec_in_day) % sec_in_hour) % sec_in_min) / second;
    std::ostringstream formattedTime;
    formattedTime << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << sec;
    return formattedTime.str(); 
}