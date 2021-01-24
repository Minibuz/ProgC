#include <stdio.h>

#include "stack.h"

int main(void) {
    stack_init();
    
    int size = stack_size();
    int is_empty = stack_is_empty();

    printf("Size : %i and Is_empty : %i\n", size, is_empty);
    return 0;
}