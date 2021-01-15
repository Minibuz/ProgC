#include <stdio.h>
#include <stdlib.h>

#define N 5

/**
 * Display all of the permutations that happens while doing them recursively
 * 
 * @param array
 * @param current
 * @param max
 */
void permutations(int buffer[], int current, int max) {
    int i;
    if(buffer == NULL) {
        printf("The array is NULL !\n");
    }
    for(i = 0; i<current-1; i++) {
        printf("\t");
    }
    putchar('[');
    for(i = 0; i<N; i++){
	    if(i == N-1){
	        printf("%d", buffer[i]);
	    }
	    else{
	        printf("%d,", buffer[i]);
	    }
    }
    printf("]\n");

    if(current>max) {
        return;
    }

    for(i = 0; i<N; i++) {
        if(buffer[i]==0) {
            buffer[i] = current;
            permutations(buffer, current+1, max);
            buffer[i] = 0;
        }
    }
}

/**
 * Create a new dynamic tab of a given size
 * 
 * @param size
 * @return Array of the given size
 */
int *allocate_integer_array(int size) {
    int *new_tab;

    new_tab = (int *)malloc((size+1) * sizeof(int));
    if(new_tab == NULL) {
        fprintf(stderr,"Memory allocation error\n");
        return NULL;
    }
    return new_tab;
}

/**
 * Fill the given array with 0
 * 
 * @param array
 */
void fill_array(int *array) {
    int i;
    for(i = 0; i < N; i++) {
        array[i] = 0;
    }
}

/**
 * Free the memory
 * 
 * @param array
 */
void free_integer_array(int *array) {
    free(array);
}

int main(int argc, char* argv[]) {
    int *tab;
    tab = allocate_integer_array(N);
    fill_array(tab);

    permutations(tab,1,N);

    free(tab);
    return 0;
}
