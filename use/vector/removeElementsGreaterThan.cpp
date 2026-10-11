#include <vector>
#include <cassert>
#include <iostream>
int removeElementsGreaterThan(std::vector<int>& v, int threshold) {
    int removed = 0;
    while (!v.empty() && v.back() > threshold) {
        v.pop_back();
        ++removed;
    }
    return removed;
}
int main() {
    std::vector<int> v{1,3,5,7,9};
    assert(removeElementsGreaterThan(v, 5) == 2);
    assert((v == std::vector<int>{1,3,5}));
    assert(removeElementsGreaterThan(v, 10) == 0);
    assert(removeElementsGreaterThan(v, 0) == 3);
    assert(v.empty());
    assert(removeElementsGreaterThan(v, 0) == 0);
    std::cout << "Tests passed!\n";
}
