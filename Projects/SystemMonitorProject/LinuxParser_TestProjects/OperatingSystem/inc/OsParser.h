#ifndef OSPARSER_H
#define OSPARSER_H

#include <fstream>
#include <regex>
#include <string>
#include <vector>

namespace OsParser
{
    // path
    const std::string kOSPath("/etc/os-release");
    const std::string kProcDirectory{"/proc/"};
    const std::string kVersionFilename{"/version"};

    // System getter
    std::string OperatingSystem();
    std::vector<int> Pids();
    std::vector<int> FilePids();


}; // namespace OsParser


#endif