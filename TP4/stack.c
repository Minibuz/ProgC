#include "stack.h"

#include <stdlib.h>

/* This module proposes a single global and static stack */
static Stack stack;

void stack_init(void) {
    stack.size = 15;
}

int stack_size(void) {
    return stack.size;
}

int stack_is_empty(void) {
    int i, result=1;
    for(i = 0; i < stack_size(); i++) {
        if(stack.values[i] != NULL) {
            result = 0;
        }
    }
    return result;
}

int stack_top(void) {
    return 1;
}

int stack_pop(void) {
    return 1;
}

void stack_push(int n) {

}

void stack_display(void) {

}

int stack_get_element(int index) {
    return 1;
}
