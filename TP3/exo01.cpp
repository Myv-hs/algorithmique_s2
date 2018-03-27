#include <array>
#include <iostream>

const unsigned int BUFF = 64;
using T = std::array<int,BUFF>;

int insrt_pos (int x, T a, int b) {
	if(b==0) return 0;
	if(x>a[b-1]) return b;
	return insrt_pos(x,a,b-1);
}

void itr_add (int x, T &a, int b) {
	int p = insrt_pos(x, a, b);
	for(int i=b;i>p;i--){
		a[i]=a[i-1];
	}
	a[p]=x;
}

void rec_add (int x, int i, T &a, int b) {
	if(b>i){
		a[b]=a[b-1];
		rec_add(x,i,a,b-1);
	} else if(b==i) a[i]=x;
}

void insrt_sort (T &a, int b){
	if(b>0){
		std::cout <<b<<">0\n";
		int p = insrt_pos(a[b-1],a,b);
		std::cout <<p<<" is the index to insert at\n";
		if(p==b-1) insrt_sort(a,b-1);
		else {
			rec_add(a[b-1],p,a,b);
			insrt_sort(a,b);
		}
	}
}

int main(){
	T a = {0,1,3,5};
	T t = {1,4,2,3};
	std::cout << insrt_pos(2,a,4) <<std::endl;
	rec_add(2,insrt_pos(2,a,4),a,4);
	insrt_sort(t,4);
	for(int i=0;i<4;i++){
		std::cout << t[i];
	}

	std::cout<<std::endl;
	return 0;
}