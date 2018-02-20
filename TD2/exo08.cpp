#include <iostream>
using namespace std;

float f (float x){
	return 2*x*x*x-4*x*x -x -1;
}

float x0 (float a, float b, float err){
	float c = (a+b)/2; 
	float y = f(c);
	if(y==0 or (c-a <= err)) return c;
	/*if(f(b)-f(a)<err) return c;
	if(y*a<0) return x0(a, c, err);
	if(y*b<0) return x0(c, b, err);*/
	if(f(a)*y < 0) return x0(a,c,err);
	else return x0(c,b,err);
}

int main (){
	float a, b, e;
	do{
		cout << "a, b = "; cin >> a >> b;
	} while (f(a)*f(b) >= 0);
	cout << "epsilon = "; cin >> e;

	cout << "f(" << x0(a,b,e) << ") ~= 0\n"; 

	return 0;
}