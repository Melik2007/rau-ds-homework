#include <iostream>
#include <array>
#include <stdexcept>
#include <string>
template<typename T, std::size_t N> class FixedArray { std::array<T,N> data{}; public: void set(int index,T value) {if(index<0||static_cast<std::size_t>(index)>=N) throw std::out_of_range("index"); data[index]=value;} const T& get(int index) const {if(index<0||static_cast<std::size_t>(index)>=N) throw std::out_of_range("index"); return data[index];} std::size_t size() const {return N;} };
int main() { FixedArray<int,3> a; a.set(0,10); std::cout<<a.get(0)<<" size="<<a.size()<<'\n'; FixedArray<std::string,2> b; b.set(1,"hello"); std::cout<<b.get(1)<<'\n'; }
