#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// Add enum State
enum class State {kempty, kObstacle};

// Write ParseLine function using string stream
std::vector<State> ParseLine(std::string board_line)
{
    // Example line: "0,1,0,1,0,"
    std::istringstream line_stream (board_line);
    std::vector<State> line{};
    int n{};
    char c{};

    while (line_stream >> n >> c && c == ',')
    {
        if (n == 0)
        {
            line.push_back(State::kempty);
        }
        else
        {
            line.push_back(State::kObstacle);
        }
    }

    return line;
}

// Write ReadBoardFile function using fstream
std::vector<std::vector<State>> ReadBoardFile(std::string board_file)
{
    std::vector<std::vector<State>> board_grid{};
    std::ifstream reader(board_file);
    std::string line{};

    if (!reader)
    {
        std::cerr << "Error opening file.." << std::endl;
    }

    while (getline(reader, line))
    {
        std::vector<State> board_line{};
        board_line = ParseLine(line);
        board_grid.push_back(board_line);
    }

    return board_grid;
}

// Write CellString function: 
    // use "⛰️  " and "0  "
std::string CellString(State cellState)
{
    switch(cellState)
    {
        case State::kObstacle : return "⛰️  ";
        break;
        default : return "0  ";
    }
}

// Write PrintBoard function
void PrintBoard(std::vector<std::vector<State>> board_grid)
{
    for (auto line : board_grid)
    {
        for (auto index : line)
        {
            std::cout << CellString(index);
        }
        std::cout << std::endl;
    }
}

// Write Search function
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> input_grid, int start[2], int goal[2])
{
    std::vector<std::vector<State>> grid{};
    std::cout << "No path found!" << std::endl;

    return grid;
}

// Write Heuristic function


// Write AddToOpen function

int main()
{
    int start[2] {0, 0};
    int goal[2] {4, 5};

    auto test_board = ReadBoardFile("files/1.board");
    auto solution = Search(test_board, start, goal);
    PrintBoard(test_board);


    return 0;
}