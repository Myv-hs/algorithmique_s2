#include <iostream>
#include <array>
using namespace std;

struct lecteur {
	int ID;
	string nom, prenom;
};

const unsigned int BUFF = 512;
using lecteurs = array<lecteur, BUFF>;
struct enslecteur {
	int n;
	lecteurs l;
};

void saisie (lecteur &a) {
	cout << "entrez ID, nom et prenom: "; cin >> a.ID >> a.nom >> a.prenom;
}

void affiche (lecteur a) {
	cout << a.nom <<' '<< a.prenom<<" :: "<<a.ID<<endl;
}

void init (enslecteur &a) {
	a.n = 0;
}

void ajoute (enslecteur &a) {
	saisie(a.l[a.n++]);
}

void ajoute (enslecteur &a, lecteur b) {
	a.n++;
	a.l[a.n-1] = b;
}

void saisieTout (enslecteur &a) {
	cout << "Combien de lecteurs a saisir: "; cin >> a.n;
	for(int i=0;i<a.n;i++){
		saisie(a.l[i]);
	}
}

void afficheTout (enslecteur a) {
	for(int i=0;i<a.n;i++){
		affiche(a.l[i]);
	}
}

string rechercheNom (enslecteur a, int b) {
	for(int i=0;i<a.n;i++){
		if(a.l[i].ID==b) return a.l[i].nom;		
	}
	return "Pas Trouve";
}

struct livre {
	string titre, auteur;
	int ISBN, lastUser;
	bool dispo;
};
using livres = array<livre, BUFF>;
struct enslivre{
	int n;
	livres l;
};
struct biblio {
	enslivre L;
	enslecteur U;
};

void emprunter (biblio &a) {}

void afficheLivre (livre a) {}

void emprunts (biblio a) {
	for(int i=0;i<a.L.n;i++){
		if(!a.L.l[i].dispo) {
			afficheLivre(a.L.l[i]);
			cout << rechercheNom(a.L.l[i].lastUser) << endl;
		}
	}
}

int main () {
	lecteur moi;
	
	cout << "saisie\n";
	saisie(moi);
	cout << "cree classe\n";
	enslecteur classe;
	cout << "init classe\n";
	init(classe);
	cout << "saisie ++classe\n";
	ajoute(classe);
	cout << "classe+moi\n";	
	ajoute(classe, moi);
	afficheTout(classe);

	return 0;
}