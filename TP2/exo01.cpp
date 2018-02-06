#include <iostream>

void bonjour (int n) {
	if(n>0){
		std::cout << "Bonjour\n";
		bonjour(n-1);
	}
}

int sum_squares_upto (int a) {
	if(a==1) return 1;
	return a*a + sum_squares_upto(a-1);
}

int main () {
	int x; std::cin >> x;
	bonjour(x);
	std::cout << sum_squares_upto(x) <<std::endl;
}