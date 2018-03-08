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