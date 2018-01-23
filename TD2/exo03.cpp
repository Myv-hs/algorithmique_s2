float puissance (float x, int n) {
	if(n==0) return 1;
	if(n<0) return 1/puissance(x,-n); // a)
	if(n%2==0) return puissance(x*x,n/2); // b) 
	return x*puissance(x,n-1);
}