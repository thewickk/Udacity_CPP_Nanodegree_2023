#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

enum class State {kEmpty, kObstacle}; 

/*
    Write a function CellString which accepts aState as input and returns the following string:

    "⛰️ " if the input equals a kObstacle
    "0 " otherwise.
*/

std::string CellString(State aState)
{
    switch (aState)
    {
    case State::kObstacle : return "⛰️   ";
        break;
    
    default: return "0   ";
    }
}

// ParseLine function to extract a vector from string stream
std::vector<State> ParseLine(std::string line)
{
    std::istringstream lineStream(line);
    std::vector<State> lineVec{};
    int state{};
    char comma{};

    while (lineStream >> state >> comma && comma == ',')
    {
        if (state == 0)
        {
            lineVec.push_back(State::kEmpty);
        }
        else
        {
            lineVec.push_back(State::kObstacle);
        }
    }

    return lineVec;
}

// ReadBoardFile reads in board from file return 2-D vector
std::vector<std::vector<State>> ReadBoardFile(std::string board_file)
{
    std::vector<std::vector<State>> the_board{};
    std::ifstream reader(board_file);
    std::string line;

    if (!reader)
    {
        std::cerr << "Error opening file..." << std::endl;
    }

    while (getline(reader, line))
    {
        std::vector<State> temp_vec = ParseLine(line);
        the_board.push_back(temp_vec);
    }

    return the_board;
}

// Print board function 2-D vector
void PrintBoard(std::vector<std::vector<State>> the_board)
{
    for (auto i : the_board)
    {
        for (auto j : i)
        {
            std::cout << CellString(j);
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<State>> the_board = ReadBoardFile("files/1.board");
    PrintBoard(the_board);

    return 0;
}