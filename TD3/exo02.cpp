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

void supprime_premier (liste & L){
	if(L != NULL){
		liste p = L;
		L = L->suiv;
		delete p;
	}
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

void ajoute_a (int n, liste& L, liste adr) {
	if(adr==NULL) ajoute_debut(n,L);
	else {
		if(L==adr)
			ajoute_debut(n,(*L).suiv);
		else
			ajoute_a(n,L->suiv,adr);
	}
}

void ajoute_apres (int n, liste& L, int x) { //prof
	ajoute_a(n,L,adresse(x,L));	
}

void supprime_premier_n (int n, liste& L){
	if(L!=NULL){
		if(L->val==n)
			supprime_premier(L);
		else supprime_premier_n(n,L->suiv);
	}
}

