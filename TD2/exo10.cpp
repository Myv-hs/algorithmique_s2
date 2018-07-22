#include <iostream>

// Prototypes
bool paire (int a);
bool impaire (int a);

bool paire (int a){
	if(a==0) return 1;
	if(a==1) return 0;
	impaire(a-1);
}

bool impaire (int a){
	if(a==0) return 0;
	if(a==1) return 1;
	paire(a-1);
}

int main (){
	int a; std::cin >>a;
	if(paire(a)) std::cout <<a<<" est paire\n";
	else std::cout <<a<<" n'est pas paire\n";
	return 0;
}