#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

// Constructor
Process::Process(int pid) 
  : pid_{pid}, cpu_utilization_{Process::CpuUtilization()} {}

// Return this process's ID
int Process::Pid() { return this->pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() 
{
  long cycles = sysconf(_SC_CLK_TCK);
  float total_time = LinuxParser::ActiveJiffies(this->pid_) / cycles;
  float seconds = LinuxParser::UpTime(this->pid_);
  return total_time / seconds;
}

// Return the command that generated this process
std::string Process::Command() { return LinuxParser::Command(this->pid_); }

// Return this process's memory utilization
std::string Process::Ram() { return LinuxParser::Ram(this->pid_); }

// Return the user (name) that generated this process
std::string Process::User() { return LinuxParser::User(this->pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->pid_); }

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& other) const 
{ 
  return other.cpu_utilization_ < this->cpu_utilization_;
}