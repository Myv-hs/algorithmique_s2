#include <iostream>
#include <array>
#include <cmath>
using namespace std;
const unsigned int buffSize = 64;

struct point {
	float x,y;
};

using points = array<point, buffSize>;
struct enspoint {
	points p;
	int nombre;
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
	for(int=0;i<a.nombre;i++){
		gx+=a.p[i].x;
		gy+=a.p[i].y;
	}
	g.x=gx/a.nombre; g.y=gy/a.nombre;
	return g;
}

void saisiePoint (point &a){
	cin >> a.x >> a.y;
}

void saisieEnsemble (enspoint &a){
	cout << "Nombre de points: ";cin>>a.nombre;
	for(int i=0;i<a.nombre;i++){
		saisiePoint(a.p[i]);
	}
}

void reduit () {
	
}

int main () {
	point A,B;
	saisiePoint(A); saisiePoint(B); 
	point C = milieu(A,B);
	cout <<"distance: " <<distance(A,B) <<" milieu ("<<C.x<<","<<C.y<<")"<<endl;
	return 0;
}