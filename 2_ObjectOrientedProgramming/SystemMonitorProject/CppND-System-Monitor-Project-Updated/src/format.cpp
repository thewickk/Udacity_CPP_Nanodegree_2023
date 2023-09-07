#include <string>
// TODO: make graders aware of these includes...
#include <iomanip>
#include <sstream>
#include <iostream>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) 
{ 
    int hours = seconds / 3600; 
    int min = ((seconds % 3600) / 60); 
    int sec = seconds % 60;
    std::stringstream formattedTime;
    formattedTime << std::to_string(hours) << ":" << std::setw(2) << std::setfill('0') << std::to_string(min) << ":" << std::setw(2) << std::setfill('0') << std::to_string(sec);
    return formattedTime.str(); 
}