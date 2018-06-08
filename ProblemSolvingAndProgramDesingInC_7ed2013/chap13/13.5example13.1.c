#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char stack_element_t;   // an alias that could easy change in a single pace, e.g. to: typedef int stack_element_t 
typedef struct stack_node_s
{
   stack_element_t element;
   struct stack_node_s *restp;
} stack_node_t;

typedef struct {stack_node_t *topp;} stack_t; //I wonder if there is a way to NOT declare a whole new struct with 1 member 
//typedef stack_node_t * stack_t;  // I mean id we could solve the exercise with such an alias definition

void push(stack_t *sp, stack_element_t c);
stack_element_t pop(stack_t *sp);

int main(void)
{
  stack_t s = {NULL}; /* stack of characters (initially empty) implemented as a pointer-to-stack_node_t */
  push(&s, '2');    /* Builds first stack of Fig. 13.23 */
  push(&s, '+');
  push(&s, 'C');
  push(&s, '/');    /* Completes second stack of Fig. 13.23 */
  printf("\nEmptying stack: \n");
  while (s.topp != NULL)    /* Empties stack element by element */
    printf("%c\n", pop(&s));
  return (0);
}

/* The value in c is placed on top of the stack accessed through sp
* Pre: the stack is defined */
void push(stack_t *sp, stack_element_t c)
{
  stack_node_t *newp; /* pointer to new stack node */
/* Creates and defines new node*/
  newp = (stack_node_t *)malloc(sizeof (stack_node_t));
  newp->element = c;
  newp->restp = sp->topp;
/* Sets stack pointer to point to new node */
  sp->topp = newp;
}

/* Removes and frees top node of stack, returning character value stored there.
* Pre: the stack is not empty */
stack_element_t pop(stack_t *sp) /* input/output - stack */
{
  stack_node_t *to_freep; /* pointer to node removed */
  stack_element_t ans; /* value at top of stack */
  to_freep = sp->topp; /* saves pointer to node being deleted*/
  ans = to_freep->element; /* retrieves value to return */
  sp->topp = to_freep->restp; /* deletes top node */
  free(to_freep);     /* deallocates space */
  return (ans);
}

// gcc -Wall -o 13.5example13.1stack 13.5example13.1.c
