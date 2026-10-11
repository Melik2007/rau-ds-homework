#include <vector>
#include <cassert>
#include <iostream>
int findSubsequence(const std::vector<int>& v, const std::vector<int>& sub) {
    if (sub.empty()) return 0;
    if (sub.size() > v.size()) return -1;
    for (std::size_t i = 0; i <= v.size() - sub.size(); ++i) {
        std::size_t j = 0;
        while (j < sub.size() && v[i+j] == sub[j]) ++j;
        if (j == sub.size()) return static_cast<int>(i);
    }
    return -1;
}
int main() {
    assert(findSubsequence({1,2,3,4,5,6}, {3,4,5}) == 2);
    assert(findSubsequence({1,2,1,2}, {1,2}) == 0);
    assert(findSubsequence({1,2}, {3}) == -1);
    assert(findSubsequence({1}, {1,2}) == -1);
    assert(findSubsequence({}, {}) == 0);
    std::cout << "Tests passed!\n";
}
