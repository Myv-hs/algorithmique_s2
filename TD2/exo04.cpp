int somme (int a) {
	if(a<10) return a;
	//if(a==0) return a; //prof
	return a%10 + somme(a/10);
}

int supersomme (int a) {
	
}