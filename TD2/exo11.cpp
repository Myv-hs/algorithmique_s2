#include <array>
#include <iostream>

const unsigned int BUFF = 512;
using tablo_int = std::array<int,BUFF>;

//a
int tablo_int_max (tablo_int T, int t) {
	if(t==1) return T[0];
	int m = tablo_int_max(T,t-1);
	if(T[t-1]>=m) return T[t-1];
	return m;
}

int main(){
	tablo_int A = {0,22,1,2,-7,19};
	std::cout << tablo_int_max(A,6) <<std::endl;

	return 0;
}