#include <iostream>
using namespace std;

struct numbers {
	int a,b;
};


void order (numbers &a) {
	int swp;
	if(a.a > a.b) return;
	else {
		swp = a.a;
		a.a = a.b;
		a.b = swp;
	}
}


int PGCD (numbers a) {
	numbers b;
	order(a);
	b.a = a.b;
	b.b = a.a%a.b;
	if(b.b==0) return b.a;
	return PGCD(b);
}

// Teacher's version
int PGCD(int a, int b){
	if(a<0) return pgcd(-a,b);
	if(b<0) return pgcd(a,-b);
	if(a<b) return pgcd(b,a);
	if(b==0) return a;
	return pgcd(b,a%b);
}

int main () {
	numbers A;
	cin >> A.a >> A.b; 
	cout << PGCD(A) << endl;

	return 0;
}