#include <vector>
#include <cassert>
#include <iostream>
#include <string>
template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& v, Predicate predicate) {
    std::vector<T> result;
    for (const auto& x : v) if (predicate(x)) result.push_back(x);
    return result;
}
bool isEven(int x) { return x % 2 == 0; }
int main() {
    assert((filterVector(std::vector<int>{1,2,3,4,5,6}, isEven) == std::vector<int>{2,4,6}));
    assert(filterVector(std::vector<int>{1,3}, isEven).empty());
    assert((filterVector(std::vector<std::string>{"a","bb","ccc"}, [](const std::string& s) { return s.size() > 1; }) == std::vector<std::string>{"bb","ccc"}));
    std::cout << "Tests passed!\n";
}
