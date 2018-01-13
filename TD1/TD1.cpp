#include <iostream>
#include <array>
#include <cmath>
using namespace std;
const unsigned int buffSize = 32;

struct point {
	float x,y;
};

using points = array<point, buffSize>;
struct enspoint {
	points p;
	int nb;
};

bool confondus (point a, point b) {
	return (a.x==b.x && a.y==b.y);
}

float distance (point a, point b) {
	float x = a.x-b.x;
	float y = a.y-b.y;
	return sqrt(x*x+y*y); 
}

/*void milieu (point &c, point a, point b) {
	c.x = (b.x+a.x)/2;
	c.y = (b.y+a.y)/2;
}
*/
point milieu (point a, point b) {
	point c;
	c.x = (b.x+a.x)/2;
	c.y = (b.y+a.y)/2;
	return c;
}

point centre (enspoint a) {
	point g;
	float gx=0, gy=0;
	for(int i=0;i<a.nb;i++){
		gx+=a.p[i].x;
		gy+=a.p[i].y;
	}
	g.x=gx/a.nb; g.y=gy/a.nb;
	return g;
}

void saisiePoint (point &a){
	cin >> a.x >> a.y;
}

void saisieEnsemble (enspoint &a){
	cout << "Nombre de points: ";cin>>a.nb;
	for(int i=0;i<a.nb;i++){
		saisiePoint(a.p[i]);
	}
}

void reduit (enspoint &a) {
	for(int i=0;i<a.nb;i++){
		for(int j=i+1;j<a.nb;j++){
			if(confondus(a.p[i],a.p[j])) {
				a.nb--;
				for(int k=j;k<a.nb;k++){
					a.p[k]=a.p[k+1];
				}
				j--;
			}
		}
	}
}

void afficheEnsemble (enspoint a) {
	for(int i=0;i<a.nb;i++){
		cout<<"p"<<i<<" ("<<a.p[i].x <<","<<a.p[i].y<<")\n";
	}
}

int main () {
	enspoint A;
	saisieEnsemble(A);
	reduit(A);
	afficheEnsemble(A);

	return 0;
}