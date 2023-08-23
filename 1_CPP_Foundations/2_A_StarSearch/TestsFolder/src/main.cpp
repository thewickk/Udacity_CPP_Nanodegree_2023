#include <iostream>
#include <vector>

// Directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    for (int i = 0; i < 4; i++)
    {
        std::cout << "{";
        for (int j = 0; j < 2; j++)
        {
            std::cout << delta[i][j] << ",";
        }
        std::cout << "}" << std::endl;
    }
    // std::vector<std::vector<int>> isOpen{};
    // std::vector<int> node {};
    // int x = 0;
    // int y = 1;
    // int g = 0;
    // int h = 8;

    // node.push_back(x);
    // node.push_back(y);
    // node.push_back(g);
    // node.push_back(h);


    // isOpen.push_back(node);
    // isOpen.push_back(std::vector<int> {0, 2, 1, 7});
    // isOpen.push_back(std::vector<int> {0, 3, 2, 6});
    // isOpen.push_back(std::vector<int> {1, 0, 3, 8});

    // std::cout << "{" << std::endl;
    // for (int x = 0; x < isOpen.size(); x++)
    // {
    //     std::cout << "  " << x << ": { ";
    //     for (int y = 0; y < isOpen[x].size(); y++)
    //     {
    //         std::cout << isOpen[x][y] <<", ";
    //     }
    //     std::cout << "}," << std::endl;
    // }
    // std::cout << "}" << std::endl;

    // int x1 = isOpen[1][0];
    // int y1 = isOpen[1][1];
    // int g1 = isOpen[1][2];
    // int h1 = isOpen[1][3];

    // std::cout << "Node 2: " << x1 << ", " << y1 << ", " << g1 << ", " << h1 << std::endl;
    return 0;
}