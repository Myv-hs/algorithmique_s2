#include <iostream>

int c (int n) {
	if(n==1) return 1;
	else return c(n-1)+2*(n-1)+1;
}

int main (){

	for(int i=1;i<=10;i++){
		int y = c(i);
		std::cout << "f("<< i <<") = " << y << std::endl;
	}
	return 0;
}