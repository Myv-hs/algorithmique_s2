// NOM : Matthew
// PRENOM : Coyle
// GROUPE : L1 MPCIE Info 2A

#include <iostream>
#include <fstream>
#include <string>
#include <array>


// 1) Déclarer les types occ_mot et liste_mots.
struct occ_mot{
	std::string mot;
	int occ;
};

struct mots {
	occ_mot m;
	mots *s;
};
using liste_mots = mots*;


// 7) Déclarer le type tab_mots.
const int BUFF = 10000;
using tab_mots = std::array<std::string, BUFF>;


// 11) Déclarer les types occ_lettre et tab_lettres.
struct occ_lettre {
	char ltr;
	int occ;
};

const int ltrBUFF = 26;
using tab_lettres = std::array<occ_lettre, ltrBUFF>;




// 2) Crée une liste vide de mots.
void initialise (liste_mots & L)
{
	L=NULL;
}

// 3) Ajoute un mot en début de liste.
void ajoute_debut (std::string mot, liste_mots & L)
{
	liste_mots tmp = new mots;
	tmp->m.mot = mot;
	tmp->m.occ = 1;
	tmp->s = L;
	L = tmp;
}


// 4) Ajoute un mot dans une liste que l'on suppose déjà triée selon le classement alphabétique des mots
//    Si le mot apparait déjà dans la liste, on incrémente son nombre d'occurrences ; la liste doit rester triée après l'ajout.
void ajoute (std::string mot, liste_mots & L)
{
	if(L!=NULL){
		if(L->m.mot == mot) L->m.occ++;
		else if (mot < L->m.mot) ajoute_debut(mot, L);
		else ajoute(mot,L->s);
	} else ajoute_debut(mot,L);
}

// 5) Affiche la liste des mots, avec leur nombre d'occurrences entre parenthèses.
void affiche (liste_mots L)
{
	if(L!=NULL){
		std::cout << L->m.mot << " ("<<L->m.occ<<") \n";
		affiche(L->s);
	}
}

// 6) Demande à l'utilisateur de saisir un ensemble de mots et les ajoute dans la liste L.
void saisit (liste_mots & L)
{
	std::string usrin;
	do {
		std::cout <<"Entrez un mot, ou FINI pour finir:"; std::cin >> usrin;
		if(usrin != "FINI") ajoute(usrin,L);
	} while(usrin != "FINI");
}




// *) Construit une liste de mots en fonction d'un texte contenu dans un fichier texte.
void construit (liste_mots & L)
{
	std::ifstream fichier("bouledesuif.txt");
	std::string mot;
	initialise(L);
	while (fichier >> mot)
		ajoute(mot,L);
}




// 8) Remplit un tableau de mots à partir d'une liste 
void remplit (tab_mots & T, int & nbmots, liste_mots L)
{
	if(L!=NULL){
		T[nbmots++]=L->m.mot;
		remplit(T,nbmots,L->s);
	}
}


// 9) Détermine si un mot appartient à un tableau de mots trié
//    Doit utiliser la recherche par dichotomie et la récursivité (définir un second sous-programme avec d'autres paramètres pour mettre en oeuvre la récursivité)
bool appartient (std::string mot, tab_mots T, int nbmots)
{
	for(int i=0;i<nbmots;i++){
		if(T[i]==mot) return true;
	}
	return false;
}

// 10) Écrire le programme principal (en fin de fichier).


/*
struct occ_lettre {
	char ltr;
	int occ;
};
const int ltrBUFF = 26;
using tab_lettres = std::array<occ_lettre, ltrBUFF>;
*/
// 12) Initialise un tableau de lettres avec les 26 lettres minuscules, et aucune occurrence pour chaque lettre.
void initialise (tab_lettres & T)
{
	for(int i=0;i<ltrBUFF;i++){
		T[i].ltr = 97+i;
		T[i].occ = 0;
	}
}

// 13) Ajoute dans un tableau de lettres une occurrence d'une lettre donnée en paramètre.
void ajoute (char lettre, tab_lettres & T)
{
	T[lettre-97].occ++;	
}

// 14) Remplit un tableau de lettres en fonction d'une liste de mots.
void comptabilise (tab_lettres & T, liste_mots L)
{
	if(L!=NULL){
		for(int j=0;j<L->m.mot.length();j++){
			for(int i=0;i<L->m.occ;i++){
				ajoute(L->m.mot[j],T);
			}		
		}
		comptabilise(T,L->s);
	}
}

// 15) Trie un tableau de lettres par ordre décroissant du nombre d'occurrences des lettres.
void trie (tab_lettres & T)
{
	int pasTrie = ltrBUFF;
	while(pasTrie){
		for(int i=0;i<pasTrie-1;i++){
			if(T[i].occ<T[i+1].occ){
				occ_lettre tmp = T[i];
				T[i]=T[i+1];
				T[i+1] = tmp;
			}
		}
		pasTrie--;
	}
}

// 16) Affiche les lettres dans l'ordre, avec leur nombre d'occurrences entre parenthèses
void affiche (tab_lettres T)
{
	for(int i=0;i<ltrBUFF;i++){
		std::cout<<T[i].ltr<<" "<<T[i].occ<<std::endl;
	}
}

//  10) 17) Programme principal
int main ()
{
	tab_lettres LTR;
	initialise(LTR);
	

	liste_mots L;
	tab_mots T;
	int nbmots=0;

	//initialise(L); //inclu dans construit
	construit(L);
	affiche(L);
	
	std::string usrin;
	std::cout << "Quel mot cherchez vous? :: "; std::cin >> usrin;
	
	remplit(T,nbmots,L);

	std::string in = (appartient(usrin,T,nbmots)) ? " " : " pas ";
	std::cout <<"\""<<usrin<<"\""<<" fait"<<in<<"parti du text\n";
	
	comptabilise(LTR, L);
	trie(LTR);
	affiche(LTR);

	return 0;
}



