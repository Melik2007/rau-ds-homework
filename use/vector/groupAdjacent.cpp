#include <vector>
#include <cassert>
#include <iostream>
std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& v) {
    std::vector<std::vector<int>> groups;
    for (int x : v) {
        if (groups.empty() || groups.back().back() != x) groups.push_back({x});
        else groups.back().push_back(x);
    }
    return groups;
}
int main() {
    assert((groupAdjacent({1,1,2,2,2,3,1,1}) == std::vector<std::vector<int>>{{1,1},{2,2,2},{3},{1,1}}));
    assert(groupAdjacent({}).empty());
    assert((groupAdjacent({5}) == std::vector<std::vector<int>>{{5}}));
    std::cout << "Tests passed!\n";
}
