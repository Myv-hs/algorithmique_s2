bool isin (char a, std::string b, int n) {
	if(n>b.length()) return 0;
	if(a==b[n-1]) return 1;
	return isin(a,b,n+1);
}