#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void recherche_dicho(int t[],int size, int value);

int main() {
    int tab[100];
    int i;

    srand(time(NULL));

	for(i=0; i<100; i++) {
		tab[i] = rand()%100;
	}
    printf("fill done");

    recherche_dicho(tab, 100, 32);

    return 0;
}

void recherche_dicho(int t[], int size, int value){
    int inf, sup, pos, millieu;
    inf=0;
    sup=size-1;
    pos=-1;

    while((inf<=sup) && (pos==-1)) {
        millieu=(sup+inf)/2;
        if(value < t[millieu]){
            sup=millieu-1;
        }
        else if(value > t[millieu]) {
            inf=millieu;
        }
        else {
            pos=millieu;
        }
    }

    if(pos==-1) {
        printf("La valeur %d n'est pas dans le tableau.\n",value);
    }
    else {
        printf("La valeur %d est la position %d.\n",value,pos);
    }
}