#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
std::vector<int> createVectorFromInput() {
    std::vector<int> v;
    int x;
    while (std::cin >> x && x != 0) v.push_back(x);
    return v;
}
int main() {
    std::istringstream input("7 8 9 0 15");
    auto* old = std::cin.rdbuf(input.rdbuf());
    auto v = createVectorFromInput();
    std::cin.rdbuf(old);
    assert((v == std::vector<int>{7, 8, 9}));
    std::cout << "Size: " << v.size() << '\n';
    for (int x : v) std::cout << x << ' ';
    std::cout << "\nTests passed!\n";
}
