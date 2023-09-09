#include "../inc/OsParser.h"
#include <iostream>

int main()
{

    std::cout << OsParser::OperatingSystem() << std::endl;
    std::vector<int> pids = OsParser::Pids();
}