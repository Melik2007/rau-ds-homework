#include <iostream>
#include <string>
template<typename T> void printElement(const T& x) { std::cout << x << '\n'; }
int main() { printElement(42); printElement(3.14); printElement(std::string("Hello")); }
