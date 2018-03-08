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

int main () {
	return 0;
}

string extrait (string e, int pos, int lg) {
	if(lg<=0) return "";
	return e[pos-1]+extrait(e,pos+1,lg-1);
}

bool estchiffre (char c) {
	const unsigned int char0 = 48;
	const unsigned int char9 = 57; 
	return (c >= char0 && c <= char9);
}

bool estsigne (char c) {
	bool sg_pl = (c==43), sg_mn = (c==45), sg_fx = (c==42), sg_dv = (c==47), sg_md = (c==37); 
	bool prt_l = (c==40), prt_r = (c==41);
	return (sg_pl or sg_mn or sg_fx or sg_dv or sg_md or prt_l or prt_r);
}