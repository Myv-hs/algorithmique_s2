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

void afficheCoord (point a){
	cout<<"( "<<a.x<<" , "<<a.y<<" )";
}

void afficheEnsemble (enspoint a) {
	for(int i=0;i<a.nb;i++){
		cout<<"p"<<i<<" "; afficheCoord(a.p[i]); cout<<endl;
	}
}

point plusproche (enspoint a) {
	point O; 
	O.x = 0, O.y = 0;
	int smallestIndex = 0;
	for(int i=1;i<a.nb;i++){
		if(distance(a.p[i],O)<distance(a.p[smallestIndex],O)){
			smallestIndex = i;
		}
	}
	return a.p[smallestIndex];
}

float distmin (enspoint a) {
	if(a.nb==1) return 0;
	float distancemin = distance(a.p[0],a.p[1]);
	for(int i=0;i<a.nb;i++) {
		for(int j=i+1;j<a.nb;j++){
			float testdist = distance(a.p[i],a.p[j]); 
			if(testdist<distancemin) distancemin = testdist;
		}
	}
	return distancemin;
}

bool tousalignes (enspoint a) {
	if(a.nb < 3 ) return 1;
	for(int i=2;i<a.nb;i++){
		if((a.p[0].x*(a.p[1].y-a.p[i].y) + a.p[1].x*(a.p[i].y-a.p[0].y) + a.p[i].x*(a.p[0].y-a.p[1].y))!=0) return 0;
	}
	return 1;
}

float min (float a, float b) {
	if(a<b) return a;
	return b;
}

float max(float a,float b){
	if (a>b) return a;
	return b;
}

enspoint contour (enspoint a) {
	enspoint retEsmbl;
	retEsmbl.nb = 4;

	float minx=a.p[0].x, maxx=a.p[0].x, miny=a.p[0].y, maxy=a.p[0].y;
	for(int i=1;i<a.nb;i++){
		minx = min(minx, a.p[i].x);
		miny = min(miny, a.p[i].y);
		maxx = max(maxx, a.p[i].x);
		maxy = max(maxy, a.p[i].y);
	}
	retEsmbl.p[0].x = minx; retEsmbl.p[0].y = miny;
	retEsmbl.p[1].x = minx; retEsmbl.p[1].y = maxy;
	retEsmbl.p[2].x = maxx; retEsmbl.p[2].y = maxy;
	retEsmbl.p[3].x = maxx; retEsmbl.p[3].y = miny;

	return retEsmbl;
}

int absord (enspoint a) {
	for(int i=1;i<a.nb;i++){
		if(a.p[i].x<a.p[i-1].x){
			for(int j=a.nb-1;j>0;j--){
				if(a.p[j].x>a.p[j-1].x){
					return 0;
				}
			}
			return -1;
		}
	}
	return 1;
}

float image (enspoint a, float x){
	float y, xl, xr, xratio, ylrdelta, ydelta;//pente;
	int c = absord(a);
	if(!c) return 0;
	
	int i, gendarmes = 0;
	if(c==1) i = 0;
	else if (c==-1) i=a.nb-1;

	do {
		gendarmes++;
		if(gendarmes>a.nb) {
			cout<<"x pas entre "<<a.p[0].x<<" et "<<a.p[a.nb-1].x<<endl;
			return 0;
		}
		//cout<<" :: x:"<<x<<" x["<<i<<"]:"<<a.p[i].x<<endl;
		if(x==a.p[i].x)return a.p[i].y;
		if(x>a.p[i].x) {
			xl=i;
		} else {
			xr=i;
			gendarmes = 0;
		}

		i+=c;
	} while(gendarmes);

	cout<<a.p[xl].x<<" < "<<x<<" < "<<a.p[xr].x<<endl;
	/*pente = (a.p[xr].y-a.p[xl].y)/(a.p[xr].x-a.p[xl].x);
	y = x*pente;*/
	xratio = (x-a.p[xl].x)/(a.p[xr].x-a.p[xl].x);
	ylrdelta = a.p[xr].y-a.p[xl].y;
	ydelta = xratio*ylrdelta;
	y=a.p[xl].y + ydelta;
	return y;
}

int main () {
	enspoint A;
	float x,y;
	saisieEnsemble(A);
	reduit(A);
	afficheEnsemble(A);
	cout << tousalignes(A)<<endl;
	cin >> x;
	y = image(A,x);
	cout << "L\'image de "<<x<<" par la fonction affine par morceaux continue representee par l'ensemble saisie:\nf("<<x<<")="<<y<<endl; 
	return 0;
}