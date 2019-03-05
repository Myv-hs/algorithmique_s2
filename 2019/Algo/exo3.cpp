#include <iostream>

float puissance (float x, int n) {
	if(n==0) return 1;
	else if (n%2==0) x * puissance(x*x,n/2);
	else if (n>0) return x * puissance(x,n-1);
	else return puissance(x,n+1)/x;
}

int main () {
	std::cout << puissance(3,-3)<<std::endl;
}