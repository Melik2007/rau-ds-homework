#include <iostream>
#include <array>
#include <stdexcept>
template<typename T,std::size_t N,std::size_t M> class Matrix { std::array<std::array<T,M>,N> data{}; public: void set(int r,int c,T value) {if(r<0||c<0||static_cast<std::size_t>(r)>=N||static_cast<std::size_t>(c)>=M) throw std::out_of_range("cell"); data[r][c]=value;} T get(int r,int c) const {if(r<0||c<0||static_cast<std::size_t>(r)>=N||static_cast<std::size_t>(c)>=M) throw std::out_of_range("cell"); return data[r][c];} void print() const {for(const auto& row:data){for(const auto& x:row) std::cout<<x<<" "; std::cout<<'\n';}} Matrix operator+(const Matrix& other) const {Matrix result; for(std::size_t i=0;i<N;++i) for(std::size_t j=0;j<M;++j) result.data[i][j]=data[i][j]+other.data[i][j]; return result;} };
int main() {Matrix<int,2,2> a,b; a.set(0,0,2); b.set(0,0,3); (a+b).print(); Matrix<double,1,2> x,y; x.set(0,1,1.5); y.set(0,1,2.5); (x+y).print();}
