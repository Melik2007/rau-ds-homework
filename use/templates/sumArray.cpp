#include <iostream>
#include <string>
template<typename T> T sumArray(const T* arr, std::size_t n) { T sum{}; for(std::size_t i=0;i<n;++i) sum+=arr[i]; return sum; }
int main() { int a[]={1,2,3}; double b[]={1.5,2.5}; std::string c[]={"Hello", " ", "world"}; std::cout<<sumArray(a,3)<<'\n'<<sumArray(b,2)<<'\n'<<sumArray(c,3)<<'\n'; }
