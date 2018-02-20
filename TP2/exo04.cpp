#include <iostream>

int fibo (int n){
	if(n<=1) return n;
	return fibo(n-1)+fibo(n-2); 
}

int fibo_non_rec (int n){
	int a=0, b=1, c;
	if(n<=1) return n;
	for(int i=0;i<n-1;i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int main () {
	int x; std::cin >>x;
	std::cout << fibo(x) << std::endl;
	std::cout << fibo_non_rec(x) <<std::endl;
	return 0;
}