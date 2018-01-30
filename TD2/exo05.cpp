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

bool isin (int x, tab a) {
	if(tab.length == 0) return 0;
	return (x==tab[0]) + isin(x)
}