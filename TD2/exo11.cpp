#include <array>
#include <iostream>
using namespace std;

const unsigned int BUFF = 512;
using tablo_int = array<int,BUFF>;

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

int plus_petit_indice_du_max_rec (tablo_int T, int n){ //Prof
	if(n==1) return 0;
	int ppi = plus_petit_indice_du_max_rec(T,n-1);
	if(T[n-1]>T[ppi]) return n-1;
	return ppi;
}

//c
void tablo_int_maxtri (tablo_int &T, int t){
	if(t<=0) return;
	int minimax = plus_petit_indice_du_max_rec(T,t);
	int swp = T[t-1];
	T[t-1] = T[minimax];
	T[minimax] = swp;
	tablo_int_maxtri(T,t-1);
}

//d
bool tablo_int_ordre_plus (tablo_int T, int t){
	if(t<=1) return 1;
	return (T[t-1]>=T[t-2])&&tablo_int_ordre_plus(T,t-1);
}

bool tablo_int_contiens (tablo_int T, int a, int b, int x){
	int c = (a+b)/2;
	if(T[c]==x) return 1;
	if(c==a || c==b) return 0;
	if(T[c]<=x) return tablo_int_contiens(T,c,b,x);
	return tablo_int_contiens(T,a,c,x);
}

int main(){
	tablo_int A = {22, 99, -32, 66, 2};
	int As = 5;
	cout << tablo_int_max(A,As) <<endl;
	tablo_int_maxtri(A,As);
	cout << tablo_int_ordre_plus(A,As)<<endl;
	cout << tablo_int_contiens(A,0,As,22)<<endl;


	return 0;
}