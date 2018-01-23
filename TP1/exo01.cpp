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

//4
fraction mult (fraction a, fraction b) {
	fraction out;
	out.n = a.n*b.n; out.d = b.d*b.d;
	return out;
}

//5
fraction add (fraction a, fraction b) {
	fraction temp, out;
	temp.n = a.n*b.d; temp.d = a.d*b.d;
	out.n = b.n*a.d; out.d = b.d*a.d;
	out.n += temp.n;
	return out;
}

//6
fraction opp (fraction a) {
	fraction out = a;
	out.n = -a;
	return out;
}

fraction inv (fraction a) {
	fraction out;
	out.n = a.d; out.d = a.n;
	return out;
}

//7
fraction sustr (fraction a, fraction b) {
	fraction temp, out;
	temp.n = a.n*b.d; temp.d = a.d*b.d;
	out.n = b.n*a.d; out.d = b.d*a.d;
	out.n -= temp.n;
	return out;
}

fraction div (fraction a, fraction b) {
	fraction temp;
	temp = inv(b);
	return mult(a,temp;)
}

int main () {
	
	return 0;
}