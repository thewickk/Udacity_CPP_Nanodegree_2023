#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <filesystem> // Used for getting Pids
#include <algorithm>  // Used to parse Pids that are ints
#include <iostream>

#include "linux_parser.h"


std::string LinuxParser::OperatingSystem() 
{
  std::string line;
  std::string key;
  std::string value;
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

std::string LinuxParser::Kernel() 
{
  std::string os, version, kernel;
  std::string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// https://en.cppreference.com/w/cpp/filesystem/directory_iterator
// https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
std::vector<int> LinuxParser::Pids() 
{
  std::vector<int> pids;
  // iterate through the /proc/ dir
  for (const auto& dir_entry : std::filesystem::directory_iterator{kProcDirectory})
  { 
    // Create a temporary string to store each directory filename
    std::string file_name(dir_entry.path().filename());
    // check to see if each element in file_name is a digit, if so push that file_name on to vector
    if (std::all_of(file_name.cbegin(), file_name.cend(), isdigit))
    {
      pids.push_back(stoi(file_name));
    }
  }
  return pids;
}

float LinuxParser::MemoryUtilization() 
{ 
  float memtotal{}, memavail{}, buffers{}, memutil{}, value{};
  std::string line{}, key{};
  std::ifstream filestream(kProcDirectory+kMeminfoFilename);
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      while (linestream >> key >> value)
      {
        if (key == "MemTotal:")
        {
            memtotal = value;
        }
        else if (key == "MemAvailable:")
        {
            memavail = value;
        }
        else if (key == "Buffers:")
        {
            buffers = value;
        }
      }
    }
    memutil = 1 - (memavail / (memtotal - buffers));
  }
  else
  {
    std::cerr << "File open error in LinuxParser::MemoryUtilization()" << std::endl;
  }

  filestream.close();
  return memutil;
}

long LinuxParser::UpTime() 
{
  long uptime{};
  std::string line{};
  std::ifstream filestream(kProcDirectory+kUptimeFilename);
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> uptime;
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::UpTime()" << std::endl;
  }

  filestream.close();   
  return uptime; 
}

long LinuxParser::ActiveJiffies(int pid) 
{ 
  std::ifstream filestream{kProcDirectory + std::to_string(pid) + kStatFilename};
  std::vector<std::string> jiffy_list{};
  std::string entry{}, line{};
  // values taken from: 
  // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
  long active_jiffies{}, utime{}, stime{}, cutime{}, cstime{};

  if ( filestream.is_open())
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    while ( linestream >> entry)
    {
      jiffy_list.push_back(entry);
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::ActiveJiffies()" << std::endl;
  }

  utime = std::stol(jiffy_list.at(14));
  stime = std::stol(jiffy_list.at(15));
  cutime = std::stol(jiffy_list.at(16));
  cstime = std::stol(jiffy_list.at(17));

  active_jiffies = utime + stime + cutime + cstime;
  
  filestream.close();
  return active_jiffies;
}

std::vector<std::string> LinuxParser::CpuUtilization() { 
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
    std::cerr << "File open error in LinuxParser::CpuUtilization()" << std::endl;
  }

  filestream.close();  
  return cpuUtil; 
}

int LinuxParser::TotalProcesses() 
{ 
  int totalprocesses{};
  std::string key{}, line{};
  std::ifstream filestream(kProcDirectory+kStatFilename);

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> totalprocesses;
      if (key == "processes"){
        return totalprocesses;
      }
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::TotalProcesses()" << std::endl;
  }

  filestream.close();  
  return totalprocesses;
}

int LinuxParser::RunningProcesses() 
{
  int runningprocesses{};
  std::string key{}, line{};
  std::ifstream filestream(kProcDirectory+kStatFilename);

  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> key >> runningprocesses;
      if (key == "procs_running"){
        return runningprocesses;
      }
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::RunningProcesses()" << std::endl;
  }

  filestream.close();  
  return runningprocesses;
}

std::string LinuxParser::Command(int pid) 
{ 
  std::ifstream filestream{kProcDirectory + std::to_string(pid) + kCmdlineFilename};
  std::string line{}, cmd{};

  if (filestream.is_open())
  { 
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> cmd;
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::Command()" << std::endl;
  }

  filestream.close();

  return cmd; 
}

std::string LinuxParser::Ram(int pid) 
{ 
  std::ifstream filestream{kProcDirectory + std::to_string(pid) + kStatusFilename};
  std::string line{}, key{};
  int value{}, kB{}, mB{};

  if ( filestream.is_open())
  {
    while ( std::getline(filestream, line) )
    {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if ( key == "VmSize:")
      {
        kB = value;
      }
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::Ram()" << std::endl;
  }

  filestream.close();
  
  mB = kB / 1000;
  return std::to_string(mB); 
}

std::string LinuxParser::Uid(int pid) 
{ 
  std::ifstream filestream{kProcDirectory + std::to_string(pid) + kStatusFilename};
  std::string line{}, key{};
  int uid{};

  if ( filestream.is_open())
  {
    while ( std::getline(filestream, line) )
    {
      std::istringstream linestream(line);
      linestream >> key >> uid;
      if ( key == "Uid:")
      {
        return std::to_string(uid);
      }
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::Uid()" << std::endl;
  }

  filestream.close();
      
  return std::to_string(uid); 
}

std::string LinuxParser::User(int pid) 
{ 
  std::string user_id = Uid(pid);
  std::ifstream filestream{kPasswordPath};
  std::string line{}, username{}, encrpt_passwd{}, uid{};

  if ( filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      linestream >> username >> encrpt_passwd >> uid;
      if ( uid == user_id)
      {
        return username;
      }
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::User()" << std::endl;
  }

  filestream.close();
  return username; 
}

long LinuxParser::UpTime(int pid)
{
  std::ifstream filestream{kProcDirectory + std::to_string(pid) + kStatFilename};
  std::vector<std::string> jiffy_list{};
  std::string entry{}, line{};
  long pid_start{}, up_time{};

  if ( filestream.is_open())
  {
    std::getline(filestream, line);
    std::istringstream linestream(line);
    while ( linestream >> entry)
    {
      jiffy_list.push_back(entry);
    }
  }
  else
  {
    std::cerr << "File open error in LinuxParser::UpTime()" << std::endl;
  }

  filestream.close();
  pid_start = std::stol(jiffy_list.at(21)) / sysconf(_SC_CLK_TCK);

  up_time = LinuxParser::UpTime() - pid_start;

  return up_time;
}
