#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<int> ParseLine(std::string boardLine)
{   
    std::vector<int> board;
    std::istringstream lineStream(boardLine);
    int n;
    char c;

    while (lineStream >> n >> c)
    {
        board.push_back(n);
    }

    return board;
}

void ReadBoardFile(std::string boardFile)
{
    std::ifstream reader;
    reader.open(boardFile);

    if (!reader)
    {
        std::cerr << "Could not open file..." << std::endl;
    }

    std::string line;
    while (getline(reader, line))
    {
        std::cout << line << std::endl;
    }
}



int main()
{
    std::string line {"0,1,0,0,0,0,"};
    std::vector<int> temp;

    std::istringstream boardStream(line);

    char c;
    int n;

    while (boardStream >> n >> c)
    {
        temp.push_back(n);
    }

    for (auto value : temp)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
    return 0;
}