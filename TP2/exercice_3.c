#include <stdio.h>
#include <stdlib.h>

void egrainer_des_nombres(int nombre);

int main(int argc, char* argv[])
{
	int entier_affiche=0;
	/*int i=0;*/

	if(argc!=2)
	{
		return 1;
	}

	entier_affiche=atoi(argv[1]);
	
	egrainer_des_nombres(entier_affiche);
	/*
	for(i=entier_affiche;i>0;i--)
	{
		printf("%d ", i);
	}
	for(i=1;i<=entier_affiche;i++)
	{
		printf("%d ", i);
	}
	*/
	printf("\n");

	return 0;
}

void egrainer_des_nombres(int nombre)
{
	printf("%d ",nombre);
	nombre--;
	if(nombre>=1)
	{
		egrainer_des_nombres(nombre);
	}
	nombre++;
	printf("%d ",nombre);
}