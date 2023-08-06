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

std::vector<std::vector<int>> ReadBoardFile(std::string boardFile)
{
    std::ifstream reader(boardFile);
    // reader.open(boardFile);
    std::vector<std::vector<int>> outerVec{};

    if (!reader)
    {
        std::cerr << "Could not open file..." << std::endl;
    }

    std::string line;
    while (getline(reader, line))
    {
        std::vector<int> innerVec = ParseLine(line);
        outerVec.push_back(innerVec);
    }

    reader.close();

    return outerVec;
}

void PrintBoard(std::vector<std::vector<int>> board)
{
    for (auto innerVec : board)
    {
        for (auto vec : innerVec)
        {
            std::cout << vec << ",";
        }
        std::cout << "\n";
    }
}



int main()
{
    std::vector<std::vector<int>> boardVec = ReadBoardFile("files/1.board");
    PrintBoard(boardVec);

    return 0;
}