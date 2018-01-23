#include <iostream>
using namespace std;

//1
struct fraction {
	int n,d;
};

//2
void saisie (fraction &a){
	cout << "gimme 2 numbers"; cin >> a.n >> a.d;
}

//3
void affichage (fraction a) {
	cout << a.n << "/" << a.d << endl;
}

int main () {
	
	return 0;
}