#include <iostream>
#include <string>
template<typename T1, typename T2> class Pair { T1 first; T2 second; public: Pair(T1 a,T2 b):first(a),second(b){} void print() const {std::cout<<first<<" "<<second<<'\n';} };
int main() { Pair<int,std::string> a(7,"days"); a.print(); Pair<double,char> b(2.5,'x'); b.print(); }
