#include <iostream>
using namespace std;

int c (int n,int k) {
	if(k==0 || n==k) return 1;
	return c(n-1,k-1)+c(n-1,k);
}

void developpe (int n) {
	for(int i=0; i<=n; i++){
		int coef = c(n,i);
		int pussA = n-i;
		if(coef>1) cout << coef;
		if(pussA) cout <<'a';
		if(pussA>1) cout <<pussA;
		if(i>0) cout << 'b';
		if(i>1) cout <<i;

		if(i<n) cout << '+';
		else cout <<endl;
	}
}

int main () {

	cout << c(3,2) << std::endl;

	developpe(4);
	return 0;
}