#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
#include <string>
void workWithEmptyVector() {
    std::vector<int> v;
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << '\n';
    }
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
}
int main() {
    std::ostringstream out;
    auto* old = std::cout.rdbuf(out.rdbuf());
    workWithEmptyVector();
    std::cout.rdbuf(old);
    for (int i = 1; i <= 10; ++i)
        assert(out.str().find("Size: " + std::to_string(i) + " Capacity: ") != std::string::npos);
    assert(out.str().find("1 2 3 4 5 6 7 8 9 10 ") != std::string::npos);
    std::cout << "Tests passed!\n";
}
