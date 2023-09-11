#include "processor.h"
#include "linux_parser.h"
#include <vector>
#include <string>
#include <iostream>

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    std::vector<std::string> cpuJiffies = LinuxParser::CpuUtilization();

    float PrevIdle{}, Idle{}, PrevNonIdle{}, NonIdle{}, PrevTotal{}, Total{}, CPU_Percentage{};
    float totald{}, idled{};

    // cast cpu stats from string to float
    float current_user = std::stof(cpuJiffies.at(LinuxParser::kUser_));
    float current_nice = std::stof(cpuJiffies.at(LinuxParser::kNice_));
    float current_system = std::stof(cpuJiffies.at(LinuxParser::kSystem_));
    float current_idle = std::stof(cpuJiffies.at(LinuxParser::kIdle_));
    float current_iowait = std::stof(cpuJiffies.at(LinuxParser::kIOwait_));
    float current_irq = std::stof(cpuJiffies.at(LinuxParser::kIRQ_));
    float current_softirq = std::stof(cpuJiffies.at(LinuxParser::kSoftIRQ_));
    float current_steal = std::stof(cpuJiffies.at(LinuxParser::kSteal_));
    float current_guest = std::stof(cpuJiffies.at(LinuxParser::kGuest_));
    float current_guest_nice = std::stof(cpuJiffies.at(LinuxParser::kGuestNice_));
    

    // https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    PrevIdle = previdle_ + previowait_;
    Idle = current_idle + current_iowait;
    PrevNonIdle = prevuser_ + prevnice_+ prevsystem_ + previrq_ + prevsoftirq_ + prevsteal_;
    NonIdle = current_user + current_nice + current_system + current_irq + current_softirq + current_steal;
    PrevTotal = PrevIdle + PrevNonIdle;
    Total = Idle + NonIdle;
    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;
    CPU_Percentage = (totald - idled) / totald;

    // After we have processed current data, update member variables so current data becomes previous data for next iteration
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

    return CPU_Percentage; 
}