#include <iostream>
#include <vector>
#include <string>
template<typename T> int linearSearch(const std::vector<T>& v, const T& target) { for(std::size_t i=0;i<v.size();++i) if(v[i]==target) return static_cast<int>(i); return -1; }
int main() { std::cout<<linearSearch(std::vector<int>{4,8,4}, 8)<<'\n'; std::cout<<linearSearch(std::vector<double>{1.1,2.2}, 2.2)<<'\n'; std::cout<<linearSearch(std::vector<std::string>{"a","b"}, std::string("b"))<<'\n'; }
