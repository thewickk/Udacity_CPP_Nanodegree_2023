#include "system.h"
#include "linux_parser.h"


// Return the system's CPU
Processor& System::GetCpu() { return cpu_; }

// Return a container composed of the system's processes
std::vector<Process>& System::GetProcesses()
{
  processes_ = {};
  auto pids = LinuxParser::Pids();
  for (int pid : pids)
  {
    Process p(pid);
    processes_.push_back(p);
  }
  std::sort(processes_.begin(), processes_.end());
  return processes_;
}

// Return the system's kernel identifier (string)
std::string System::GetKernel() { return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::GetMemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// Return the operating system name
std::string System::GetOperatingSystem() { return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system
int System::GetRunningProcesses() { return LinuxParser::RunningProcesses(); }

// Return the total number of processes on the system
int System::GetTotalProcesses() { return LinuxParser::Pids().size(); }

// Return the number of seconds since the system started running
long int System::GetSystemUpTime() { return LinuxParser::UpTime(); }