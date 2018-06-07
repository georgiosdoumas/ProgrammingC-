/* Write the functions get_params and show described in the database inquiry problem.
Since get_params calls function menu_choose, your implementation of algorithm step 4  for get_params
must be sure to account for the fact that menu_choose does not validate the value the user enters. */

// Actually I used the techniques presented in chapter 12 to seperate the program in 3 files

#include "11.3exercise.programming1.h"

/* Displays all products in the database that satisfy the search parameters specified by the program user. */
int main(void)
{
  char inv_filename[STR_SIZ];
  FILE *inventoryp;
  search_params_t params;
  printf("Enter name of inventory file> ");
  scanf("%s", inv_filename);
  inventoryp = fopen(inv_filename, "rb");
  params = get_params();             /* Get the search parameters and ... */
  display_match(inventoryp, params); /* ...display all products that satisfy them*/
  return(0);
}

// gcc -Wall -o 11.3exercise.programming1 11.3exercise.programming1.functions.c 11.3exercise.programming1.c
