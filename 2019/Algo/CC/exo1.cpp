#include <iostream>

bool apparetient (int nombre, int chiffre) {
	//on suppose que chiffre est un entier necessairement compris entre 0 et 9
	//std::cout <<nombre<<std::endl;
	if(nombre<0) nombre *=-1; //abs(nombre)
	if(nombre < 10) return (nombre==chiffre);
	return (nombre%10==chiffre) or apparetient(nombre/10,chiffre);

}

int main () {

	std::cout << apparetient(-312,1) << std::endl; 	//1
	std::cout << apparetient(0,0) << std::endl; 	//1
	std::cout << apparetient(663,0) << std::endl; 	//0
	std::cout << apparetient(9196,2) << std::endl; 	//0

	return 0;
}