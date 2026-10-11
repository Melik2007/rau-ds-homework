#include <iostream>
#include <string>
template<typename T> void mySwap(T& a, T& b) { T temp = a; a = b; b = temp; }
int main() { int a=1,b=2; mySwap(a,b); std::cout<<a<<" "<<b<<'\n'; double x=1.5,y=2.5; mySwap(x,y); std::cout<<x<<" "<<y<<'\n'; std::string s="cat",t="dog"; mySwap(s,t); std::cout<<s<<" "<<t<<'\n'; }
