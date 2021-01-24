#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mot_minuscules(char* mot, int taille);
int valeur_numerique(char* mot, int taille);
int puissance(int puissance);
void minuscules_to_nombre(char* mot, int taille);
void nombres_to_minuscules(int valeur);

int main(int argc, char *argv[]){
	if(argc<2){
		fprintf((stderr), "Veuillez entrez un arguments en entrant la fonction\n" );
	}
	else{
		if(mot_minuscules(argv[1], strlen(argv[1]))){
			printf("%s est un mot en minuscules\n", argv[1]);
			printf("La valeur %s en base 10 est", argv[1]);
			minuscules_to_nombre(argv[1], strlen(argv[1]));
		}
		else if(valeur_numerique(argv[1], strlen(argv[1]))){
			printf("%s est un nombre\n", argv[1]);
			printf("La valeur %s en base 26 est \"",argv[1]);
			nombres_to_minuscules(atoi(argv[1]));
			putchar("\"");
			putchar('\n');
		}
		else{
			fprintf(stderr, "%s n'est ni un mot entièrement en minuscules ou une valeur numériques.\n", argv[1]);
		}
	}
	return 0;

}

int mot_minuscules(char* mot, int taille){
	int retour=1,i=0;
	for(i=0;(unsigned long)i<taille*sizeof(char);i++){
		if(!(mot[i]>='a' && mot[i]<='z')){
			retour = 0;
		}
	}
	return retour;
}
int valeur_numerique(char* mot, int taille){
	int retour=1,i=0;
	for(i=0;(unsigned long)i<taille*sizeof(char);i++){
		if(!(mot[i]>='0' && mot[i]<='9')){
			retour = 0;
		}
	}
	return retour;
}

int puissance(int puissance){
   int resultat = 1;
   int compteur = 1;
   while(compteur<=puissance){
      resultat *= 26;
      compteur++;
   }
   return resultat;
}

void minuscules_to_nombre(char* mot, int taille){
	int i=0, y=0,valeur=0;
	for(i=(taille*sizeof(char))-1,y=0;i>=0;i--,y++){
		switch(mot[i]){
			case 'a': valeur += y==0?0:(0*puissance(y)); break;
			case 'b': valeur += y==0?1:(1*puissance(y)); break;
			case 'c': valeur += y==0?2:(2*puissance(y)); break;
			case 'd': valeur += y==0?3:(3*puissance(y)); break;
			case 'e': valeur += y==0?4:(4*puissance(y)); break;
			case 'f': valeur += y==0?5:(5*puissance(y)); break;
			case 'g': valeur += y==0?6:(6*puissance(y)); break;
			case 'h': valeur += y==0?7:(7*puissance(y)); break;
			case 'i': valeur += y==0?8:(8*puissance(y)); break;
			case 'j': valeur += y==0?9:(9*puissance(y)); break;
			case 'k': valeur += y==0?10:(10*puissance(y)); break;
			case 'l': valeur += y==0?11:(11*puissance(y)); break;
			case 'm': valeur += y==0?12:(12*puissance(y)); break;
			case 'n': valeur += y==0?13:(13*puissance(y)); break;
			case 'o': valeur += y==0?14:(14*puissance(y)); break;
			case 'p': valeur += y==0?15:(15*puissance(y)); break;
			case 'q': valeur += y==0?16:(16*puissance(y)); break;
			case 'r': valeur += y==0?17:(17*puissance(y)); break;
			case 's': valeur += y==0?18:(18*puissance(y)); break;
			case 't': valeur += y==0?19:(19*puissance(y)); break;
			case 'u': valeur += y==0?20:(20*puissance(y)); break;
			case 'v': valeur += y==0?21:(21*puissance(y)); break;
			case 'w': valeur += y==0?22:(22*puissance(y)); break;
			case 'x': valeur += y==0?23:(23*puissance(y)); break;
			case 'y': valeur += y==0?24:(24*puissance(y)); break;
			case 'z': valeur += y==0?25:(25*puissance(y)); break;
		}
	}
	printf("%d\n", valeur);
}

void nombres_to_minuscules(int valeur){
	if(valeur<26){
		putchar('a'+valeur);
	}
	else{
		nombres_to_minuscules(valeur/26);
		putchar('a'+valeur%26);
	}
}