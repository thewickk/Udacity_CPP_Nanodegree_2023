#include <iostream>
#include <filesystem>

int main()
{
    const std::filesystem::path pidPath{"/proc/"};

    for (const auto& dir_entry : std::filesystem::directory_iterator{pidPath})
    {
        std::string filename(dir_entry.path().filename());
        if (std::all_of(filename.cbegin(), filename.cend(), isdigit)) {
            int pid = stoi(filename);
            std::cout << "PID: " << pid << std::endl;
        }
    }

    return 0;
}