#include <iostream>
#include "ncurses_display.h"
#include "system.h"
#include "../include/linux_parser.h"

using namespace LinuxParser;

int main() {
  // std::string os_test = LinuxParser::OperatingSystem();
  // std::cout << "OS? " << os_test << std::endl;
  // std::vector<int> test = LinuxParser::Pids();
  // for (const auto& pid : test)
  // {
  //   std::cout << "PID: " << pid << std::endl;
  // }
  System system;
  NCursesDisplay::Display(system);

}