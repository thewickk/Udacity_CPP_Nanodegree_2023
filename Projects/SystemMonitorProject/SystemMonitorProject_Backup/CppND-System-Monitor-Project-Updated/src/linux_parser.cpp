#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

vector<int> LinuxParser::Pids() {

  vector<int> pids{};
  const std::filesystem::path pidPath{kProcDirectory};

  for (const auto& dir_entry : std::filesystem::directory_iterator{pidPath})
  {
      std::string filename(dir_entry.path().filename());
      if (std::all_of(filename.cbegin(), filename.cend(), isdigit)) {
          int pid = stoi(filename);
          pids.push_back(pid);
      }
  }

  return pids;
}

float LinuxParser::MemoryUtilization(){     
  float MemTotal{}, MemAvailable{}, Buffers{}, MemUtil{};
  std::string line{}, key{}, kB{};
  float value{};
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open())
  {
      while (std::getline(filestream, line))
      {
          std::istringstream linestream(line);
          while (linestream >> key >> value >> kB)
          {
              if (key == "MemTotal:")
              {
                  MemTotal = value;
              }
              else if (key == "MemAvailable:")
              {
                  MemAvailable = value;
              }
              else if (key == "Buffers:")
              {
                  Buffers = value;
              }
          }
      }
      MemUtil = 1 - (MemAvailable / (MemTotal - Buffers));
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kMeminfoFilename << std::endl;
  }

  filestream.close();
  return MemUtil;

}

long LinuxParser::UpTime() { 
  
  long procSeconds{};
  std::string line{};
  std::ifstream filestream(kProcDirectory + kUptimeFilename);
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> procSeconds;
    }
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kUptimeFilename << std::endl;
  }

  filestream.close();
  return procSeconds; 
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { 
  return 0; 
}

vector<string> LinuxParser::CpuUtilization() { 
  std::vector<std::string> cpuUtil{};
  std::string cpu{}, user{}, nice{}, system{}, idle{}, iowait{}, irq{}, softirq{}, steal{}, guest{}, guest_nice{}, line{};
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open())
  {
      while (std::getline(filestream, line))
      {
          std::istringstream linestream(line);
          while (linestream >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice)
          {
              if (cpu == "cpu")
              {
                  cpuUtil.push_back(user);
                  cpuUtil.push_back(nice);
                  cpuUtil.push_back(system);
                  cpuUtil.push_back(idle);
                  cpuUtil.push_back(iowait);
                  cpuUtil.push_back(irq);
                  cpuUtil.push_back(softirq);
                  cpuUtil.push_back(steal);
                  cpuUtil.push_back(guest);
                  cpuUtil.push_back(guest_nice);
              }
          }
      }
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kStatFilename << std::endl;
  }

  filestream.close();  
  return cpuUtil; 
}

int LinuxParser::TotalProcesses() { 
  std::string line{}, key{};
  int processes{};
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open())
  {
      while (std::getline(filestream, line))
      {
          std::istringstream linestream(line);
          linestream >> key >> processes;
          if (key == "processes")
          {
            filestream.close();
            return processes;
          }
      }
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kStatFilename << std::endl;
  }

  filestream.close();
  return processes;
  }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  int running_procs{};
  std::string line{}, key{};
  std::ifstream filestream(kProcDirectory + kStatFilename);
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> running_procs;
      if (key == "procs_running")
      {
         filestream.close();
         return running_procs;
      }
    }
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kStatFilename << std::endl;
  }

  filestream.close();
  return running_procs;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) {

  std::ifstream filestream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  std::string line{}, command{}; 

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> command;
    }
  }
  else
  {
    std::cerr << "Couldn't open file: " << kProcDirectory + kStatFilename << std::endl;
  }

  filestream.close();
  return command; 
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) { return 0; }
