#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// Add enum State
enum class State {kempty, kObstacle, kClosed};

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

// Write Heuristic function
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 -x1) + abs(y2 - y1);
}

// Write AddToOpen function
/*
Write a void AddToOpen function which accepts the following arguments:

Four ints, one for each of the x, y, g, and h values.
References to one vector<vector<int>> for the vector of open nodes.
Reference to one vector<vector<State>> for the grid.

The AddToOpen function should do two things:
    Create a vector<int> node with the form {x, y, g, h} and push the node to the back of the open vector.
    Set the grid value for the x and y coordinates to the enum value kClosed. We have added kClosed to the set of enum values.
*/

void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNodes, std::vector<std::vector<State>> &grid)
{
    
    openNodes.push_back(std::vector<int> {x, y, g, h});
    grid[x][y] = State::kClosed;

}

// Write Search function
/*
Initialize variables with the starting node values as follows:
- x and y are given by the init variable values,
- Set the initial cost g = 0,
- h is given by Heuristic function.

Add first node to open vector using the AddToOpen function by passing the node values: x, y, g, and h, along with the open and grid vectors.
*/
std::vector<std::vector<State>> Search(std::vector<std::vector<State>> grid, int init[2], int goal[2]) // init [x1, y1], goal [x2, y2]
{

    // Create the vector of open nodes:
    std::vector<std::vector<int>> open {};

    // Initialize the starting node:
    int x = init[0];
    int y = init[1];

    // Use AddToOpen to add the starting node to the open vector
    // Set the initial cost of g = 0
    int g {0};
    // h is given by Heuristic function
    int h = Heuristic(x, y, goal[0], goal[1]);
    AddToOpen(x, y, g, h, open, grid);
    
    std::cout << "No path found!" << std::endl;

    return std::vector<std::vector<State>>{};
}


int main()
{
    int start[2] {0, 0};
    int goal[2] {4, 5};

    auto test_board = ReadBoardFile("files/1.board");
    auto solution = Search(test_board, start, goal);
    PrintBoard(test_board);


    return 0;
}