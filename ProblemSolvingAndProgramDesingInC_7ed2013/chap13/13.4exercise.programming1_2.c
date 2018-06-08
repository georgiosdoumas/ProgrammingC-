/* 1. Write a function that finds the length of a list of list_node_t nodes.
*  2. Write a recursive version of function search . */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SENT -1
typedef struct list_node_s 
{
  int digit;
  struct list_node_s *restp;
} list_node_t;

void print_list(list_node_t *headp)  /* recursive version of print function */
{
  if (headp == NULL)
    printf("\n");
  else
  {
    printf("%d", headp->digit);
    print_list(headp->restp);
  }
}

/* Forms a linked list of an input list of integers terminated by SENT */
list_node_t * get_list(void)
{
  int data;
  list_node_t *ansp;
  scanf("%d", &data);
  if (data == SENT)
    ansp = NULL;
  else
  {
    ansp = (list_node_t *)malloc(sizeof (list_node_t));
    ansp->digit = data;
    ansp->restp = get_list();   // recursively calling get_list()
  }
  return (ansp);
}

/* Searches a list iteratively for a specified target value. Returns a pointer to
* the first node containing target if found. Otherwise returns NULL. */
list_node_t * search(list_node_t *headp, int target)
{
  list_node_t *cur_nodep; // pointer to node currently being checked
  cur_nodep = headp;
  if (cur_nodep->digit == target)
    return (cur_nodep);
  else
  {
    cur_nodep = headp->restp;
    return search(cur_nodep, target);
  }
}

int list_length(list_node_t *headp)
{
  int length=0;
  list_node_t *cur_nodep; /* pointer to node currently being checked */
  if (headp == NULL)
    return 0;
  else
  {
    for(cur_nodep = headp; cur_nodep != NULL; cur_nodep = cur_nodep->restp)
      ++length;
  }
  return length;
}

int main(void)
{
  list_node_t *pi_fracp; /* list of digits to store  value of pi or whatever else */
  list_node_t *partial_listp;
  int list_size, search_digit;
  printf("Enter digits (leaving a space between them) for value of pi (give -1 as last digit and ENTER):");
  pi_fracp = get_list();
  list_size = list_length(pi_fracp);
  printf("You gave %d digits of PI \n", list_size);
  print_list(pi_fracp);
  printf("Enter the digit to search for, in the above list: ");
  scanf("%d", &search_digit);
  partial_listp = search(pi_fracp, search_digit);
  print_list(partial_listp);
  return 0;
}

// gcc -Wall -o 13.4exercise.programming1_2 13.4exercise.programming1_2.c
