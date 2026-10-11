#include <iostream>
#include <cstring>
template<typename T> bool isEqual(const T& a,const T& b) {return a==b;}
template<> bool isEqual<const char*>(const char* const& a,const char* const& b) {if(!a||!b) return a==b; return std::strcmp(a,b)==0;}
int main() {std::cout<<std::boolalpha<<isEqual(3,3)<<'\n'; const char a[]="hello",b[]="hello"; const char* p=a; const char* q=b; std::cout<<isEqual(p,q)<<'\n';}
