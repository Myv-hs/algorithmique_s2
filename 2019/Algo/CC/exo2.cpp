float calcul(float n) {
	if(n<1) return 1;
	//int a = calcul(n-1); //optimisation
	return calcul(n-1)+1/calcul(n-1);
}

float calcul2(int n) {
	float out = 1;
	for(int i=1;i<=n;i++){
		out = out+1/out;
	}
	return out;
}

#include <iostream>
int main () {

	std::cout <<"\ncalcul:"<<std::endl;
	for(int i=0;i<=10;i++){
		std::cout<< calcul(float(i))<< std::endl;
	}

	std::cout <<"\ncalcul2:"<<std::endl;
	for(int i=0;i<=10;i++){
		std::cout<< calcul(float(i))<< std::endl;
	}

	return 0;
}