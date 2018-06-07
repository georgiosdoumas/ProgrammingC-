#include "11.3exercise.programming1.h"
#include <ctype.h>
/* Prompts the user to enter the search parameters */
search_params_t get_params(void)
{
  /* body of get_params to be inserted */
  search_params_t params_range = { MIN_STOCK, MAX_STOCK, "aaaa", "zzzz", "aaaaa", "zzzzz", 0.0, MAX_PRICE };
  char editchar = 'q'; // just a character to enter the do-while loop, it will be changed in the loop
  do {
    editchar = menu_choose(params_range);
    edit_params(editchar, &params_range);
  } while(editchar != 'q');
  return params_range;
}

/*Displays records of all products in the inventory that satisfy search parameters.
* Pre: databasep accesses a binary file of product_t records that has been opened as an input file,
       and params is defined */
void display_match(FILE *databasep, search_params_t params)
{
  product_t next_prod;      /* current product from database */
  int no_matches = 1;       /* flag indicating if no matches have been found */
  int status;               /* input file status */
/*Advances to first record with a stock number greater than or equal to lower bound. */
  for (status = fread(&next_prod, sizeof (product_t), 1, databasep);
        status == 1 && params.low_stock > next_prod.stock_num;
          status = fread(&next_prod, sizeof (product_t), 1, databasep)) {}
          /* Displays a list of the products that satisfy the search parameters */
  printf("\nProducts satisfying the search parameters:\n");
  while (next_prod.stock_num <= params.high_stock && status == 1)
  {
    if (match(next_prod, params))
    {
      no_matches = 0;
      show(next_prod);
    }
    status = fread(&next_prod, sizeof (product_t), 1, databasep);
  }
  if (no_matches)   /* Displays a message if no products found */
    printf("Sorry, no products available\n");
}

/* Following functions needed by get_params and display_match */

/*Displays a lettered menu with the current values of search parameters.
 Returns the letter the user enters. A letter in the range a..h selects a parameter to change;
 q quits, accepting search parameters shown.
 Post: first nonwhitespace character entered is returned */
char menu_choose(search_params_t params) /* input - current search parameter bounds */
{
  char choice;
  printf("Select by letter a search parameter to set or enter q to\naccept parameters shown.\n");
  printf("    Search parameter             Current value\n");
  printf("[a] Low bound for stock number   %4d\n", params.low_stock);
  printf("[b] High bound for stock number  %4d\n", params.high_stock);
  printf("[c] Low bound for category       %s\n", params.low_category);
  printf("[d] High bound for category      %s\n", params.high_category);
  printf("[e] Low bound for technical description %s\n", params.low_tech_descript);
  printf("[f] High bound for technical description %s\n", params.high_tech_descript);
  printf("[g] Low bound for price         $%7.2f\n", params.low_price);
  printf("[h] High bound for price        $%7.2f\n\n", params.high_price);
  printf("Selection> ");
  scanf(" %c", &choice);
  return (choice);
}

/* Determines whether record prod satisfies all search parameters */
int match(product_t prod, search_params_t params)
{
  return ( strcmp(params.low_category, prod.category) <= 0
          && strcmp(prod.category, params.high_category) <= 0
          && strcmp(params.low_tech_descript, prod.tech_descript) <= 0
          && strcmp(prod.tech_descript, params.high_tech_descript) <= 0
          && params.low_price <= prod.price
          && prod.price <= params.high_price );
}

/* Displays each field of prod. Leaves a blank line after the product display. */
void show(product_t prod)
{
  //printf("Function show entered with product number %d\n", prod.stock_num);
  printf("%d %s %s %lf $ \n",prod.stock_num, prod.category, prod.tech_descript, prod.price);
}

/* Edits the passed (as pointer) params. I decidec to implement the function this way: */
void edit_params(char editch, search_params_t * params_ptr)
{
  char * lowLabel = "New low bound for";
  char * highLabel = "New high bound for";
  switch (editch)
  {
    case 'a': printf(" %s stock number:", lowLabel);
              scanf("%d", &params_ptr->low_stock);
              break;
    case 'b': printf(" %s stock number:", highLabel);
              scanf("%d", &params_ptr->high_stock);
              break;
    case 'c': printf(" %s category:", lowLabel);
              scanf("%s", params_ptr->low_category);  //only sinlge-word will be a good imput! 
              break;
    case 'd': printf(" %s category:", highLabel);
              scanf("%s", params_ptr->high_category);
              break;
    case 'e': printf(" %s technical description:", lowLabel);
              scanf("%s", params_ptr->low_tech_descript);
              break;
    case 'f': printf(" %s technical description:", highLabel);
              scanf("%s", params_ptr->high_tech_descript);
              break;
    case 'g': printf(" %s price:", lowLabel);
              scanf("%lf", &params_ptr->low_price);
              break;
    case 'h': printf(" %s price:", highLabel);
              scanf("%lf", &params_ptr->high_price);
              break;
    case 'q' : printf(" Editing session finished. We have the parameters to use for searching.\n");
               break;
    default: printf(" Choice %c not recognized. Please enter an acceptable letter \n", editch);
  }
}
