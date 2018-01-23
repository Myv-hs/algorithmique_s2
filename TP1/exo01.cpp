#include <iostream>
using namespace std;

//1
struct fraction {
	int n,d;
};

struct nbmixite {
	int signe;
	int ent;
	fraction frac;
};

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
	if(out.d<0) {
		out.d *=-1;
		out.m *=-1;
	}
	return out;
}

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
	return simple(out);
}

//5
fraction add (fraction a, fraction b) {
	fraction temp, out;
	temp.n = a.n*b.d; temp.d = a.d*b.d;
	out.n = b.n*a.d; out.d = b.d*a.d;
	out.n += temp.n;
	return simpl(out);
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
	return add(a,inv(b));
}

fraction div (fraction a, fraction b) {
	return mult(a,inv(b));
}

//11
nbmixite mixte (fraction a) {
	nbmixite out;

	out.frac = a;

	if(a.n<0 || a.d<0) out.signe = -1;
	else out.signe = 1;

	out.ent = a.n/a.d;

	if(out.ent>0) out.frac.n = a.n%a.d;

	return out;
}

nbmixite addM (nbmixite a, nbmixite b) {

}

int main () {

	return 0;
}