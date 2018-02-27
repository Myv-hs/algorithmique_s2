#include <array>
//#include <iostream>

const unsigned int BUFF = 8;
using int_line = std::array<int, BUFF>;
using matrix = std::array<int_line, BUFF>;

void Rec_fill (matrix &reloaded, int linesize, int colsize){
	if(linesize !=0 && colsize !=0) {
		reloaded[linesize-1][colsize-1] = (linesize-1)*BUFF+colsize;
		Rec_fill(reloaded, linesize-1, colsize);
		Rec_fill(reloaded, linesize, colsize-1);
	}
} //ultra pas opti

void Matrix_fill (matrix &a, int cols, int lines, int i) {
	if(i<=cols*lines){
		int line = (i-1)/cols;
		int col = (i-1)-line*cols;
		a[line][col]=i;
		Matrix_fill(a, cols, lines,i+1);
	}
}

/*void affiche (matrix a){
	for(int i=0;i<BUFF;i++){
		for(int j=0;j<BUFF;j++){
			std::cout << a[i][j] << " ";
		}
		std::cout<<std::endl;
	}
}*/

int main () {
	matrix A;
	Matrix_fill(A, BUFF, BUFF, 1);
	//affiche(A);
	return 0;
}