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
	out.n = -a.n;
	return out;
}

fraction inv (fraction a) {
	fraction out;
	out.n = a.d; out.d = a.n;
	return out;
}

//7
fraction sustr (fraction a, fraction b) {
	fraction temp = inv(b);
	return add(a,temp);
}

fraction div (fraction a, fraction b) {
	fraction temp;
	temp = inv(b);
	return mult(a,temp);
}

//8
int pgcd (int a, int b){
	if(a<0) return pgcd(-a,b);
	if(b<0) return pgcd(a,-b);
	if(a<b) return pgcd(b,a);
	if(b==0) return a;
	return pgcd(b,a%b);
}

//9
fraction simpl (fraction a) {
	fraction out;
	int p = pgcd(a.n,a.d);
	out.n = a.n/p; out.d = a.d/p;
	return out;
}

int main () {

}