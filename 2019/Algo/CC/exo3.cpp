#include <iostream>

//
#include <array>
const int NMAX = 100;
using TAB = std::array<int,NMAX>;

//a
void affecte_numero (TAB &t, int n) {
	if(n==0) return;
	affecte_numero(t, n-1);
	t[n-1]=n;
}

//b
int position (TAB t, int i, int n, int x){
	// position(t,0,n,valeur a' trouver)
	// retourn -1 si la valeur appartient pas a' t
	if(i==n) return -1;
	if(t[i]==x) return i;
	return position(t,i+1,n,x);
}

//c
void swap (int &a, int &b) {
	int c = a;
	a=b;
	b=c;
}

void Inverser(TAB &t, int i, int j){
	// Inverser(t,0,n-1)
	if(i>=j) return;
	swap(t[i],t[j]);
	Inverser(t,i+1,j-1);
}

//Tester Code
void affiche_tab (TAB T,int n){
	for(int i=0;i<n;i++){
		std::cout << "T["<<i<<"] : "<< T[i] <<std::endl;
	}
}

int main () {

	TAB t;
	int n = 10;
	affecte_numero(t,n);
	affiche_tab(t,n);
	Inverser(t,0,n-1);
	affiche_tab(t,n);
	std::cout << position(t,0,n,4) << std::endl;
	return 0;
}