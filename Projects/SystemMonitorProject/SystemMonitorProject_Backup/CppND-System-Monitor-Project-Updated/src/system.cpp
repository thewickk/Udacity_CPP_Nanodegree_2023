#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"
#include "format.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

Processor& System::Cpu() { return cpu_; }

// Return a vector of system processes
vector<Process>& System::Processes() { 
    
    // Create a set of unique pids sorted least to greatest
    std::set<int, std::less<int>> pidSet{};
    // Get the vector of pids from the LinuxParser
    auto pids = LinuxParser::Pids();

    // Add the pids to Systems member vector
    for (const auto& pid : pids)
    {
        // Call constructor
        Process p(pid);
        processes_.push_back(p);
    }
    return processes_; 
}

std::string System::Kernel() { return LinuxParser::Kernel(); }

float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

long int System::UpTime() {  return LinuxParser::UpTime(); }