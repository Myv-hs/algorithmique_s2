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

//b
int tablo_int_max_index (tablo_int T, int t, int mx){
	if(t==1) {
		if(T[0]==mx) return 0;
		return -1;
	}
	int idx = tablo_int_max_index(T,t-1,mx);
	if(T[t-1]==mx && (idx<0 || t-1<idx)) return t-1;
	return idx;
}

int plus_petit_indice_du_max_rec (tablo_int T, int n){
	if(n==1) return 0;
	int ppi = plus_petit_indice_du_max_rec(T,n-1);
	if(T[n-1]>T[ppi]) return n-1;
	return ppi;
}

int main(){
	tablo_int A = {0,22,1,44,-7,19};
	std::cout << tablo_int_max(A,6) <<std::endl;
	std::cout << tablo_int_max_index(A,6,tablo_int_max(A,6)) <<std::endl;
	std::cout << plus_petit_indice_du_max_rec(A,6) <<std::endl;

	return 0;
}