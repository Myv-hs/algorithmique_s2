#include <iostream>
#include <array>

const int buffSize = 64;
using tab = std::array<int, buffSize>;

void saisieRec (tab &a, int n) {
	/*if(n==0) return;
	cin >> a[n-1];
	saisieRec(a,n-1);*/

	if(n){
		saisieRec(a,n-1);
		cin >> a[n-1];
	}	
}

bool isin (int x, tab a, int n) {
	//return (n>0) && (x==tab[n-1]) || isin(x, a, n-1);
	if(n == 0) return 0;
	return (x==tab[n-1]) || isin(x, a, n-1);
}

int indexOf(int x, tab a, int n) {
	if(n==0) return -1;
	if(x==a[n-1]) return n-1;
	return indexOf(x,a,n-1);
}

bool identiques (tab t1, tab t2, int n){
	if(n==0) return 1;
	if(t1[n-1] != t2[n-1]) return false;
	return identiques(t1,t2,n-1);
}

bool tabloMemeVal (tab a, tab &b, int n) {
	if(n==0) return 1;
	int indexAinB = indexOf(a[n-1], b, n);
	if(indexAinB>=0){
		int swp = b[n-1];
		b[n-1] = b[indexAinB];
		b[indexAinB] = swp;
	} else return 0;
	return tabloMemeVal(a, b, n-1);
}