#include <iostream>
#include <string>
using namespace std;

struct personne {
	string nom, prenom, tel;
};

struct element {
	personne pers;
	element *suiv;
};
using repertoire = element*;

void initRep (repertoire & R){
	R=NULL;
}

void ajouterEnTete (string nom, string prenom, string tel, repertoire& R){
	repertoire tmp = new element;
	tmp->pers.nom = nom;
	tmp->pers.prenom = prenom;
	tmp->pers.tel = tel;
	tmp->suiv=R;
	R = tmp;
}

void ajouterEnQueue (string nom, string prenom, string tel, repertoire& R){
	if (R==NULL) ajouterEnTete(nom,prenom,tel,R);
	else ajouterEnQueue(nom,prenom,tel,R->suiv);
}

void afficherPersonne (personne P){
	cout <<"Prenom: "<< P.prenom << endl;
	cout <<"Nom: "<< P.nom << endl;
	cout <<"tel: "<< P.tel << endl;
}

void afficherRepertoire (repertoire R){
	if(R!=NULL){
		afficherPersonne(R->pers);
		afficherRepertoire(R->suiv);
	}
}

string telephone (string nom, string prenom, repertoire R){
	if(R==NULL) return "";
	if(R->pers.nom == nom and R->pers.prenom == prenom) return R->pers.tel;
	return telephone(nom,prenom,R->suiv);
}

int rechercherPosition (string nom, string prenom, repertoire R) {
	if(R==NULL) return 0;
	if(R->pers.nom==nom and R->pers.prenom==prenom) return 1;
	int out = 1 + rechercherPosition(nom,prenom,R->suiv);
	out = out*rechercherPosition(nom,prenom,R->suiv);
	return out;
}

int main (){
	repertoire A;
	initRep(A);
	ajouterEnQueue("Bar","Foo","666",A);
	ajouterEnQueue("Azzi","Yasmina","06 69 69 69 69",A);
	ajouterEnQueue("Coyle","Charlotte","03 14 15 92 65",A);
	afficherRepertoire(A);
	cout << "pos:"<<rechercherPosition("Azzi", "Yasmina", A) <<endl;
	return 0;
}