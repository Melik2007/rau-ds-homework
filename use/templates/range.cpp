#include <iostream>
template<typename T> class Range {T start,end; public: Range(T a,T b):start(a),end(b){} bool contains(const T& value) const {return start<=value && value<=end;} auto length() const -> decltype(end-start) {return end-start;} void print() const {std::cout<<'['<<start<<", "<<end<<"]\n";} };
int main() {Range<int> a(3,10); a.print(); std::cout<<a.contains(5)<<" length="<<a.length()<<'\n'; Range<double> b(1.5,4.5); b.print(); std::cout<<b.contains(2.0)<<" length="<<b.length()<<'\n'; Range<char> c('a','f'); c.print(); std::cout<<c.contains('d')<<" length="<<c.length()<<'\n';}
