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

int bookIndex(biblio a, int b) {
	for(int i=0;i<a.L.n;i++){
		if(a.L.l[i].ISBN==b) return i;		
	}
	return -1;
}

int userIndex(biblio a, int b) {
	for(int i=0;i<a.L.n;i++){
		if(a.U.l[i].ID==b) return i;		
	}
	return -1;
}

void emprunter (biblio &a, int b, int c) {
	int book = bookIndex(a,b), user = userIndex(a,c);
	if(book<0 || user<0 ) return;
	if(!a.L.l[book].dispo) return;

	a.L.l[book].dispo=0;
	a.L.l[book].lastUser=a.U.l[user].ID;
}

void afficheLivre (livre a) {
	cout << a.titre <<"\npar "<< a.auteur<<"\nISBN "<<a.ISBN<<" :: dispo? "<<a.dispo<<" :: Emprunte precedament par "<<a.lastUser<<endl;
}

void emprunts (biblio a) {
	for(int i=0;i<a.L.n;i++){
		if(!a.L.l[i].dispo) {
			afficheLivre(a.L.l[i]);
		}
	}
}

int main () {
	biblio CU;
	CU.L.n = 5;
	CU.L.l[0].titre = "Harry Potter"; CU.L.l[0].auteur = "JK Rowling"; CU.L.l[0].ISBN=9; CU.L.l[0].dispo=1; CU.L.l[0].lastUser=0;
	CU.L.l[1].titre = "A Song of Ice & Fire"; CU.L.l[1].auteur = "GRR Martin"; CU.L.l[1].ISBN=21; CU.L.l[1].dispo=1; CU.L.l[1].lastUser=0;
	CU.L.l[2].titre = "Fifty Shades of Grey"; CU.L.l[2].auteur = "ur mom"; CU.L.l[2].ISBN=12; CU.L.l[2].dispo=1; CU.L.l[2].lastUser=0;
	CU.L.l[3].titre = "Wikipedia"; CU.L.l[3].auteur = "my mom"; CU.L.l[3].ISBN=1; CU.L.l[3].dispo=1; CU.L.l[3].lastUser=0;
	CU.L.l[4].titre = "Omniverse"; CU.L.l[4].auteur = "Francis of the Filth"; CU.L.l[4].ISBN=420; CU.L.l[4].dispo=1; CU.L.l[4].lastUser=0;

	CU.U.n = 2;
	CU.U.l[0].ID = 27; CU.U.l[0].nom = "Coyle"; CU.U.l[0].prenom = "Matthew";
	CU.U.l[1].ID = 9; CU.U.l[0].nom = "leFranc"; CU.U.l[0].prenom = "Cedric";


	//test emprunts
	emprunter(CU, 21, 27); emprunter(CU, 420, 27); emprunter(CU, 9, 9);
	emprunts(CU);

	return 0;
}