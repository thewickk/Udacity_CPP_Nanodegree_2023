#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

// Init enum class
enum class State {kEmpty, kObstacle};

// Write the ParseLine function to create a vector of State from a string stream of ints and chars: 0,1,0,etc...
std::vector<State> ParseLine(std::string board_line)
{
    std::istringstream line_stream(board_line);
    std::vector<State> innerVector{};
    int number{};
    char comma{};

    while (line_stream >> number >> comma && comma == ',')
    {
        if (number == 0)
        {
            innerVector.push_back(State::kEmpty);
        }
        else
        {
            innerVector.push_back(State::kObstacle);
        }
    }

    return innerVector;
}

std::vector<std::vector<State>> ReadBoardFile(std::string board_file)
{
    std::vector<std::vector<State>> board{};
    std::string line{};
    std::ifstream reader{board_file};

    if (!reader)
    {
        std::cerr << "Couldn't open file for reading...\n";
    }

    while (getline(reader, line))
    {
        std::vector<State> inner_vector = ParseLine(line);
        board.push_back(inner_vector);
    }

    return board;
}

std::string CellString(State kState)
{
    switch(kState)
    {
        case State::kObstacle :  return "⛰️   ";
        break;

        default : return "0   ";
    }
}

void PrintBoard(std::vector<std::vector<State>> board)
{
    for (auto i : board)
    {
        for (auto j : i)
        {
            std::cout << CellString(j);
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<State>> Search(std::vector<std::vector<State>> board_grid, int start[2], int goal[2])
{
    std::vector<std::vector<State>> stubVec{};
    std::cout << "No path found!" << std::endl;

    return stubVec;
}

int main()
{
    int init[2] {0, 0};
    int goal[2] {4, 5};
    std::vector<std::vector<State>> the_board = ReadBoardFile("files/1.board");
    std::vector<std::vector<State>> solution = Search(the_board, init, goal);
    PrintBoard(solution);
    return 0;
}