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

