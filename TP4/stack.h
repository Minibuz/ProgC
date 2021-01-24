#ifndef _STACK_
#define _STACK_

#define MAX_SIZE 15

typedef struct stack {
    int values[MAX_SIZE];
    int size;
}Stack;

/* Initialize correctly the stack. */
void stack_init(void);

/* Return the current size of the stack. */
int stack_size(void);

/* Return 1 if the stack if empty, return 0 otherwise. */
int stack_is_empty(void);

/* Return the element at the top of the stack. */
int stack_top(void);

/* Pops the element at the top of the stack and returns it. */
int stack_pop(void);

/* Pushs a given integer 'n' at the top of the stack. */
void stack_push(int n);

/* Displays the content of the stack on the standard output. */
void stack_display(void);

/* Returns the element at index 'index' inside the stack. The user is
   responsible of the use of this function. The answers may not be
   relevant if a call is done outside the current size of the
   stack. */
int stack_get_element(int index);

#endif