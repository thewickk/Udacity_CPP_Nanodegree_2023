#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

// Add enum State
enum class State {kempty, kObstacle, kClosed, kPath};

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


// Write the comparison function:
/*
Write a function bool Compare that accepts two nodes of type vector<int> as arguments. 
It should return a boolean true if the f-value of the first argument is greater than the f-value of the second, 
and it should return false otherwise. Recall that the f-value is the sum of the cost and heuristic: f = g + h.
*/
bool Compare(const std::vector<int> node1, const std::vector<int> node2)
{
    int f1 = node1[2] + node1[3];
    int f2 = node2[2] + node2[3];
    return f1 > f2;
}

// Sort the 2D vector of ints in descending order
void CellSort(std::vector<std::vector<int>> *v)
{
    std::sort(v->begin(), v->end(), Compare);
}

// Write Heuristic function
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 -x1) + abs(y2 - y1);
}

// Write AddToOpen function
void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNodes, std::vector<std::vector<State>> &grid)
{
    
    openNodes.push_back(std::vector<int> {x, y, g, h});
    grid[x][y] = State::kClosed;

}

// Write Search function
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

    // TODO: while open vector is non empty {
    while (open.size() > 0)
    {
        // TODO: Sort the open list using CellSort, and get the current node.
        CellSort(&open);
        std::vector<int> current = open.back();
        open.pop_back();

        // TODO: Get the x and y values from the current node,
        x = current[0];
        y = current[1];

        // and set grid[x][y] to kPath.
        grid[x][y] = State::kPath;

        // TODO: Check if you've reached the goal. If so, return grid.
        if (x == goal[0] && y == goal[1]) return grid;
        
        // If we're not done, expand search to current node's neighbors. This step will be completed in a later quiz.
        // ExpandNeighbors
  
    } // TODO: End while loop
  
    // We've run out of new nodes to explore and haven't found a path.
    std::cout << "No path found!" << std::endl;

    return std::vector<std::vector<State>>{};
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

int main()
{
    int start[2] {0, 0};
    int goal[2] {4, 5};

    auto test_board = ReadBoardFile("files/1.board");
    auto solution = Search(test_board, start, goal);
    PrintBoard(test_board);


    return 0;
}