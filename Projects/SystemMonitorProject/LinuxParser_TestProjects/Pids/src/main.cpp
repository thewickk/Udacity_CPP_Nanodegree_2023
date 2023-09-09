#include <iostream>
#include <set>
#include <vector>
#include <filesystem>

std::vector<int> Pids() {

  std::vector<int> pids{};
  const std::filesystem::path pidPath{"/proc"};

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


int main()
{
    
    std::set<int, std::less<int>> pidSet{};
    std::vector<int> pids{Pids()};
    for (const auto& pid : pids)
    {
        pidSet.insert(pid);
    }

    for (const auto& i : pidSet)
    {
        std::cout << "PID: " << i << std::endl;
    }

    return 0;
}