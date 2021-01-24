#include <stdio.h>
#include <stdlib.h>

int calcul_puissance(int a, int n);
int calcul_puissance_recursive(int a, int n, int step);

int main(int argc, char* argv[]){
	int retour=0, retour_recursive=0;
	int a=0;
	int n=0;

	argc--;

	if(argc!=2){
		fprintf(stderr, "There's %d arguments, and the program only need two of them.\n",argc);
		return 1;
	}

	a = atoi(argv[1]);
	n = atoi(argv[2]);
	if(n<=0)
	{
		fprintf(stderr, "Le deuxième argument ne peut etre égal ou inférieur à 0\n");
		return 1;
	}

	retour = calcul_puissance(a,n);
	retour_recursive = calcul_puissance_recursive(a,n,a);

	printf("Normal : %d^%d=%d\n", a, n, retour);
	printf("Récursif : %d^%d=%d\n", a, n, retour_recursive);
	return 0;
}

int calcul_puissance(int a, int n){
	int a_puissance_n=a;
	int i=0;

	for( i=1; i<n; i++){
		a_puissance_n = a_puissance_n * a ;
	}

	return a_puissance_n;
}

int calcul_puissance_recursive(int a, int n,int step){
	int a_puissance_n=step*a;
	int i=n-1;

	if(i>1)
		a_puissance_n = calcul_puissance_recursive(a_puissance_n,i,step);

	return a_puissance_n;
}
