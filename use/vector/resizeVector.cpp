#include <vector>
#include <iostream>
#include <cassert>
#include <string>
template <typename T>
void printVector(const std::vector<T>& v) {
    for (const auto& x : v) std::cout << x << ' ';
    std::cout << '\n';
}
template <typename T>
void resizeVector(std::vector<T>& v, std::size_t newSize, const T& value) {
    printVector(v);
    v.resize(newSize, value);
    printVector(v);
}
int main() {
    std::vector<int> v{1,2,3};
    resizeVector(v, 5, 42);
    assert((v == std::vector<int>{1,2,3,42,42}));
    resizeVector(v, 2, 0);
    assert((v == std::vector<int>{1,2}));
    std::vector<std::string> s{"a"};
    resizeVector(s, 3, std::string("x"));
    assert((s == std::vector<std::string>{"a","x","x"}));
    std::cout << "Tests passed!\n";
}
