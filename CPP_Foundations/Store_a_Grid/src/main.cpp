#include <iostream>
#include <vector>

void PrintBoard(std::vector<std::vector<int>> v)
{
    for (auto vecIndex : v)
    {
        for (auto index : vecIndex)
        {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> board
    {
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    PrintBoard(board);

    return 0;
}