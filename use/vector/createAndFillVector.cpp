
#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

void createAndFillVector(int n) {
    std::vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }

    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';
}

int main() {
    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    createAndFillVector(5);

    std::cout.rdbuf(old);

    std::string result = output.str();
    assert(result.find("1 2 3 4 5") != std::string::npos);
    assert(result.find("Size: 5") != std::string::npos);

    std::cout << "Tests passed!\n";
    return 0;
}
