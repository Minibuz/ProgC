#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int entier_1=0;
	int entier_2=0;
	int somme=0;

	if(argc!=3)
	{
		printf("Veuillez entrez deux nombres après l'appel du programme.\n");
		return 1;
	}

	entier_1 = atoi(argv[1]);
	entier_2 = atoi(argv[2]);
	printf("Entier 1: %d \nEntier 2: %d \n",entier_1,entier_2);
	somme=entier_1+entier_2;
	printf("%d+%d=%d\n",entier_1,entier_2,somme);
	return 0;
}