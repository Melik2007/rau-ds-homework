#include <vector>
#include <iostream>
#include <cassert>
void manageCapacity(std::vector<int>& v) {
    std::cout << "Before: size=" << v.size() << " capacity=" << v.capacity() << '\n';
    v.reserve(v.size() + 500);
    for (int i = 1; i <= 500; ++i) v.push_back(i);
    std::cout << "After: size=" << v.size() << " capacity=" << v.capacity() << '\n';
}
int main() {
    std::vector<int> v{8,9};
    manageCapacity(v);
    assert(v.size() == 502);
    assert(v.capacity() >= 502);
    assert(v[0] == 8 && v[1] == 9 && v[2] == 1 && v.back() == 500);
    std::cout << "Tests passed!\n";
}
