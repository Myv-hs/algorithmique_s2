#include <iostream>
using namespace std;

//2
bool palindrome_rec (string a, int b, int c) {
	if(b>c) return 1;
	return (a[b]==a[c])&&palindrome_rec(a,b+1,c-1);
}

bool palindrome (string a){
	int b = 0;
	int c = a.length()-1;
	return palindrome_rec(a, b, c);
}

//1
string sub_string (string a, int i, int size) {
	if(size == 0) return "";
	return a[i]+sub_string(a,i+1,size-1);
}

//2 Correct
bool palindrome_correct (string a){
	if(a.length()<=1) return 1;
	return (a[0]==a[a.length()-1])&&palindrome_correct(sub_string(a,1,a.length()-2));
}

//3
int occurance_lettre (string a, char b) {
	if(a.length()==0) return 0;
	return (a[0]==b)+occurance_lettre(sub_string(a,1,a.length()-1),b);
}

int main () {
	string a; cin >> a;
	cout << palindrome_correct(a) <<endl;
	cout << occurance_lettre(a,'a') <<endl;

	return 0;
}