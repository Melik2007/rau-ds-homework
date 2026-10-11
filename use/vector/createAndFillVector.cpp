#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
void createAndFillVector(int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i + 1;
    for (int x : v) std::cout << x << ' ';
    std::cout << "\nSize: " << v.size() << "\nCapacity: " << v.capacity() << '\n';
}
int main() {
    std::ostringstream out;
    auto* old = std::cout.rdbuf(out.rdbuf());
    createAndFillVector(5);
    std::cout.rdbuf(old);
    assert(out.str().find("1 2 3 4 5 ") != std::string::npos);
    assert(out.str().find("Size: 5") != std::string::npos);
    std::cout << "Tests passed!\n";
}
