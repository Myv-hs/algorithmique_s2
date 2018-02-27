#include <iostream>
using namespace std;

void hanoi (int a, int t1, int t2, int t3) {
	if(a>0){
		hanoi(a-1, t1, t3, t2);
		std::cout << "Piece "<<a<<" de la tour "<<t1<<" a "<<t3<<std::endl;
		hanoi(a-1, t2, t1, t3);
	}
}

int main (){
	hanoi(3, 1,2,3);
	return 0;
}