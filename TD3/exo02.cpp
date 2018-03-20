#include <iostream>

struct element { //prof
	int val;
	element *suiv;
};
using liste = element *;

void init (liste& L) { //prof
	L = NULL;
}

bool est_vide (liste L) { //prof
	return L == NULL;
}

void ajoute_debut (int n, liste& L) { //prof
	liste p;
	p = new element;
	(*p).val = n;
	p->suiv = L;
	L=p;
}

void ajoute_fin (int n, liste& L){
	if (L==NULL) ajoute_debut(n,L);
	else ajoute_fin(n,L->suiv);
}

bool appartient (int n, liste L) { //prof
	if (L==NULL) return false;
	else if ((*L).val == n) return true;
	else return appartient(n,(*L).suiv);
	// ou : return (L!=NULL) and (((*L).val) == n) or appartient(n,(*L).suiv);
}

list adresse (int n, liste L) { //prof
	if((L==NULL) or (L->val == n)) return L;
	else return adresse(n,L->suiv);
}

void ajoute_a (int x, int n, liste L) {
	
}