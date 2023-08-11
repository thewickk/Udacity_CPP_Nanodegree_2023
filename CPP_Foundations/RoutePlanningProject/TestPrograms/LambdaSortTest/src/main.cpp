#include <iostream>
#include <vector>
#include <algorithm>

typedef struct 
{
    float x;
    float y;
    float g;
    float h;
} Node;

int main()
{
    std::vector<Node> open_list {};
    Node node1 {1, 1, 10, 11};  // 21
    Node node2 {2, 2, 15, 3};   // 18
    Node node3 {3, 3, 12, 6};   // 18
    Node node4 {4, 4, 23, 1};   // 24

    open_list.push_back(node1);
    open_list.push_back(node2);
    open_list.push_back(node3);
    open_list.push_back(node4);

    std::cout << "pre sort\n";
    for (auto const &node : open_list)
    {
        std::cout << node.g << std::endl;
    }

    std::sort(open_list.begin(), open_list.end(), [](Node a, Node b) { return (a.g + a.h) > (b.g + b.h); });

    // Should be: 23, 10, 15, 12
    std::cout << "post sort\n";
    for (auto const &node : open_list)
    {
        std::cout << node.g << std::endl;
    }

    return 0;
}