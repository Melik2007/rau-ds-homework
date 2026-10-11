#include <iostream>
template<typename T> void printValue(const T& value) {std::cout<<value<<'\n';}
template<> void printValue<bool>(const bool& value) {std::cout<<(value?"true":"false")<<'\n';}
template<> void printValue<char*>(char* const& value) {std::cout<<'"'<<value<<'"'<<'\n';}
int main() {int n=5; bool b=true; char text[]="hello"; char* p=text; printValue(n); printValue(b); printValue(p);}
