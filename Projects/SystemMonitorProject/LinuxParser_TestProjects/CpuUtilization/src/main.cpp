#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/*
    Reference
    clewis@ubuntu:build$ cat /proc/stat
    cpu  334945 4143 906108 528057413 1364 0 11490 0 0 0
*/

unsigned long prevuser_ = 0;
unsigned long prevnice_ = 0;
unsigned long prevsystem_ = 0;
unsigned long previdle_ = 0;
unsigned long previowait_ = 0;
unsigned long previrq_ = 0;
unsigned long prevsoftirq_ = 0;
unsigned long prevsteal_ = 0;
unsigned long prevguest_ = 0;
unsigned long prevguest_nice_ = 0;

std::vector<std::string> CpuUtilization() 
{ 
    std::vector<std::string> cpuUtil;
    std::string cpu, user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice, line, key;
    std::ifstream filestream("/proc/stat");
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
    return cpuUtil; 
}

// CPU
enum CPUStates {
  kUser_ = 0,
  kNice_,
  kSystem_,
  kIdle_,
  kIOwait_,
  kIRQ_,
  kSoftIRQ_,
  kSteal_,
  kGuest_,
  kGuestNice_
};


float Utilization() 
{ 
    std::vector<std::string> cpuJiffies = CpuUtilization();
    float idle, non_idle, total, cpu_percent, previous_idle, previous_non_idle, previous_total;
    float total_diff, idle_diff;
    float current_user = std::stof(cpuJiffies.at(kUser_));
    float current_nice = std::stof(cpuJiffies.at(kNice_));
    float current_system = std::stof(cpuJiffies.at(kSystem_));
    float current_idle = std::stof(cpuJiffies.at(kIdle_));
    float current_iowait = std::stof(cpuJiffies.at(kIOwait_));
    float current_irq = std::stof(cpuJiffies.at(kIRQ_));
    float current_softirq = std::stof(cpuJiffies.at(kSoftIRQ_));
    float current_steal = std::stof(cpuJiffies.at(kSteal_));
    float current_guest = std::stof(cpuJiffies.at(kGuest_));
    float current_guest_nice = std::stof(cpuJiffies.at(kGuestNice_));
    

    // https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    previous_idle = previdle_ + previowait_;
    idle = current_idle + current_iowait;
    previous_non_idle = prevuser_ + prevnice_+ prevsystem_ + previrq_ + prevsoftirq_ + prevsteal_;
    non_idle = current_user + current_nice + current_system + current_irq + current_softirq + current_steal;
    previous_total = previous_idle + previous_non_idle;
    total = idle + non_idle;
    total_diff = total - previous_total;
    idle_diff = idle - previous_idle;
    cpu_percent = (total_diff - idle_diff) / total_diff;

    prevuser_ = current_user;
    prevnice_ = current_nice;
    prevsystem_ = current_system;
    previdle_ = current_idle;
    previowait_ = current_iowait;
    previrq_ = current_irq;
    prevsoftirq_ = current_softirq;
    prevsteal_ = current_steal;
    prevguest_ = current_guest;
    prevguest_nice_ = current_guest_nice;

    return cpu_percent; 
}


int main()
{
    float testCpu = Utilization();
   

    std::cout << testCpu << "% | 100%" << std::endl;

    return 0;
}