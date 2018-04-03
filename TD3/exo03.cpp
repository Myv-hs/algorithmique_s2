struct monome {
	float coeff;
	int pow;
};
struct polyelem {
	monome a;
	polynomes *suiv;
};
using polynome = polyelem *;

void insererEnTete (polynome &P, monome m) {
	polynome p = new polyelem;
	p->a = m;
	p->suiv = P;
	P = p;
}

int degre (polynome P) {
	if(P==NULL) return 0;
	if(P->suiv == NULL) return P->a.pow;
	int nxt = degre(P->suiv);
	if(nxt < P->a.pow) return P->a.pow;
	return nxt;
}

float pow (float x, int p){
	if(p==0) return 1;
	return x*pow(x,p-1);
}

float pow_it(float x, int p){ //prof
	float out = 1;
	for(int i=0;i<=p;i++){
		out = out * x;
	}
	return out;
}

float valeurEn (polynome P, float x) {
	if(P==NULL) return 0;
	return P->a.coeff*pow(x, P->a.pow)+valeurEn(P->suiv, x);
}