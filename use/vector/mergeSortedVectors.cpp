#include <vector>
#include <cassert>
#include <iostream>
std::vector<int> mergeSortedVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());
    std::size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}
int main() {
    assert((mergeSortedVectors({1,3,5,7}, {2,4,6,8,9}) == std::vector<int>{1,2,3,4,5,6,7,8,9}));
    assert((mergeSortedVectors({}, {1,1}) == std::vector<int>{1,1}));
    assert((mergeSortedVectors({-2,1}, {-2,3}) == std::vector<int>{-2,-2,1,3}));
    std::cout << "Tests passed!\n";
}
