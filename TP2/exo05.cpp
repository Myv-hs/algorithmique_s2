#include <iostream>
using namespace std;

bool within_err(float y, float e){
	if(y<0) y=y*-1;
	return (y<=e);
}

float racine_dicho (float x, float e, float a, float b) {
	float c = (a+b)/2;
	if(within_err(c*c-x,e)) return c;
	if(c*c<=x) {
		return racine_dicho(x,e,c,b);
	}
	return racine_dicho(x,e,a,c);
}

/*float racine_heron (float x, float e) {

}*/

void racine (float x, float e){
	cout<<"Par methode dichometrique on trove sqrt(x) = "<<racine_dicho(x, e, 0, x)<<endl;
}

int main () {
	float a,e;
	cin>>a>>e;
	racine(a,e);
	return 0;
}