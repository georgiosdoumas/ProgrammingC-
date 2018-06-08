/* Complete the given code fragment so it will create a linked list containing the
musical scale if the input is
do re mi fa sol la ti do */
// Actually the input can be : do re mi fa sol la ti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct scale_node_s
{
  char note[4];
  struct scale_node_s *linkp;
} scale_node_t;

int main(void)
{
  scale_node_t *scalep, *prevp, *newp;
  int i;
  scalep = (scale_node_t *)malloc( sizeof(scale_node_t) );
  printf("Enter the 7 notes: ");  // user inputs : do re mi fa sol la ti do (and presses ENTER)
  scanf("%s", scalep->note);
  prevp = scalep;
  for (i = 0; i < 7; ++i)
  {
    newp = (scale_node_t *)malloc( sizeof(scale_node_t) );
    scanf("%s", newp->note);
    prevp->linkp = newp;
    prevp = newp;
  }
  newp = NULL;
  printf("Head of list : %s \n next element is : %s \n", scalep->note, scalep->linkp->note);
  printf("Whole list is : " );
  scale_node_t * indexp;
  //for (indexp = scalep; indexp->linkp != NULL; indexp++ ) // NOT correct output:
  // Whole list is : <do><><re><><mi><><fa><><sol><><la><><ti><>
  for (indexp = scalep; indexp->linkp != NULL; indexp = indexp->linkp ) // this is the correct! 
    printf("<%s>", indexp->note);
  puts("\n");
  return 0;
}

// gcc -Wall -o 13.3exercise.self-check2 13.3exercise.self-check2.c
