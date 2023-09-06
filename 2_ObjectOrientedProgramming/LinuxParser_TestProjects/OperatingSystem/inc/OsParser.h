#ifndef OSPARSER_H
#define OSPARSER_H

#include <fstream>
#include <regex>
#include <string>

namespace OsParser
{
    // path
    const std::string kOSPath("/etc/os-release");

    // System getter
    std::string OperatingSystem();


}; // namespace OsParser


#endif