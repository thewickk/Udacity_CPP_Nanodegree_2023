#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  Processor& GetCpu();                   
  std::vector<Process>& GetProcesses();  
  float GetMemoryUtilization();          
  long GetSystemUpTime();                      
  int GetTotalProcesses();               
  int GetRunningProcesses();             
  std::string GetKernel();               
  std::string GetOperatingSystem();      

 private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
};

#endif