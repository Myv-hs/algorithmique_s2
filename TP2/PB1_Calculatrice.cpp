#include <iostream>
using namespace std;

string extrait (string e, int pos, int lg);
bool estsigne (char c);
bool estchiffre (char c);
int parent_ouvertes (string e);
int cherchesigne (string e, int pos);
int num (char c);
int convertit (string n);
int calcule (int g, char signe, int d);
int evalue (string e);
bool valide (string e);
void saisie ();

//Codes Characteres:
const unsigned int PLUS = 43, MOINS = 45;
const unsigned int MULT = 42, DIVI = 47, MOD = 37;
const unsigned int PARL = 40, PARR = 41;
const unsigned int NUM0 = 48, NUM9 = 57;

int main () {
	string a = "-13";
	char b = '7';
	cout << (convertit(a)+num(b))*-1;
	return 0;
}

string extrait (string e, int pos, int lg) {
	if(lg<=0) return "";
	return e[pos]+extrait(e,pos+1,lg-1);
}

int num (char c) {
	return c-NUM0;
}

int convertit (string n){
	if(n.length()==0) return 0;
	if(n[0]==MOINS) return convertit(extrait(n,1,n.length()-1))*-1;
	if(n[0]==PLUS) return convertit(extrait(n,1,n.length()-1));
	return num(n[n.length()-1])+10*convertit(extrait(n,0,n.length()-1));
}

bool estchiffre (char c) {
	return (c >= NUM0 && c <= NUM9);
}

bool estsigne (char c) {
	return (c==PLUS or c==MOINS or c==MULT or c==DIVI or c==MOD or c==PARL or c==PARR);
}

int parent_ouvertes (string e) {
	if (e.length()<=0) return 0;
	int out=0;
	if(e[0]==PARL) out = 1;
	else if (e[0]==PARR) out = -1; 
	return out+parent_ouvertes(extrait(e,1,e.length()-1));
}

int calcule (int g, char signe, int d) {
	if(signe==PLUS) return g+d;
	if(signe==MOINS) return g-d;
	if(signe==MULT) return g*d;
	if(signe==DIVI) return g/d;
	if(signe==MOD) return g%d;
}