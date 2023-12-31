#include "../inc/OsParser.h"
#include <iostream>
#include <vector>
#include <dirent.h>
#include <filesystem>

std::string OsParser::OperatingSystem()
{
    std::string line;   // one line from /etc/os-release
    std::string key;    // will be PRETTY_NAME
    std::string value;  // will be Ubuntu 18.04.6 LTS

    std::ifstream filestream(kOSPath);
    if (filestream.is_open())
    {
        while (std::getline(filestream, line))
        {
            // Transform: PRETTY_NAME="Ubuntu 18.04.6 LTS" --->  PRETTY_NAME  Ubuntu_18.04.6_LTS
            std::replace(line.begin(), line.end(), ' ', '_'); // for each line if there is whitespace replace with an underscore
            std::replace(line.begin(), line.end(), '=', ' '); // for each line if there is an '=', replace it with a space
            std::replace(line.begin(), line.end(), '"', ' ');
            std::cout << "Formatted line: " << line << std::endl;

            // Now turn every newly formatted line in to an input stringstream
            std::istringstream linestream(line);

            // Loop through each line until we fine "PRETTY NAME" then we know we have our desired string
            while (linestream >> key >> value)
            {
                if (key == "PRETTY_NAME")
                {
                    std::replace(value.begin(), value.end(), '_', ' ');
                    std::cout << "Value: " << value << std::endl;
                    return value;
                }
            }
        }
    }
    // if we are here we didn't find the OS name... return the value
    std::cout << "Missed Value: " << value << std::endl;
    return value;
}

// BONUS: Update this to use std::filesystem
std::vector<int> OsParser::Pids() {
  std::vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      std::string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  for (const auto& pid : pids)
  {
    std::cout << "PID: " << pid << std::endl;
  }
  return pids;
}


std::vector<int> OsParser::FilePids()
{
    std::vector<int> pids;
    std::filesystem pidPath =

    return pids;

}