#include <stdio.h>
#include <string.h>

void wc(char*, int taille);

int main(int argc, char* argv[]){
	char input[1024];
	int i=0;

	argc--;argv++;

	printf("Entrez un mot, une phrase, n'importe quoi : ");
    for( i = 0; (unsigned long) i < 1024*sizeof(char); i+=1 ){
        scanf("%c",&input[i]);
        if(input[i] == '\n' && input[i-1] == '\n')
            break;
    }

	wc(input, 1024);

	return 0;
}

void wc(char* input, int taille){
	int characteres=0,mots=1,lignes=1,i=0;

	for(i=0;(unsigned long)i<=taille*sizeof(char);i++)
	{
		if(*(input+i)=='\0'){
			i = taille*sizeof(char);
		}
		else{
			switch(*(input+i)){
			case '\n': 
		        lignes++;
		        mots++;
		        break;
		    case ' ':
		    case '\t':
		        mots++; 
		        break;
		    default: 
		        characteres++; 
		        break;
		}
		}
	}
	mots-=2;lignes-=2;

	printf("Il y a %d characteres, %d mots et %d lignes\n",characteres,mots,lignes);
}