#include <iostream>
#include <string>
#include <fstream>

void ReadBoardFile(std::string boardFile)
{
    std::ifstream reader;
    reader.open(boardFile);

    if (!reader)
    {
        std::cerr << "There was a problem opening the file... aborting" << std::endl;
    }

    std::string line;
    while (getline(reader, line))
    {
        std::cout << line << std::endl;
    }

    reader.close();
}

int main()
{
    ReadBoardFile("files/1.board");
    return 0;
}