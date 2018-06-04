/* Define a recursive intersection function that computes set1 [intersection] set2 .
Then, define an iterative version of the same function. */  // I did not do the iterative version
// Below is the full implementation of 9.5 case study , with some changes in main to check for valid sets
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SETSIZ 65 /* 52 uppercase and lowercase letters, 10 digits,{, }, and '\0' */
#define TRUE 1
#define FALSE 0
int is_empty(const char *set);
int is_element(char ele, const char *set);
int is_set(const char *set);
int is_subset(const char *sub, const char *set);
char *set_union(char *result, const char *set1, const char *set2);
char *intersection( char *result, const char *set1, const char *set2);
void print_with_commas(const char *str);
void print_set(const char *set);
char *get_set(char *set);

int main(void)
{
  char ele, set_one[SETSIZ], set_two[SETSIZ], set_result[SETSIZ];
  printf("A set is entered as a string of up to %d letters and digits\n", SETSIZ - 3);
  printf("enclosed in {} (no duplicate characters)\n");
  printf("For example, {a, b, c} is entered as {abc}\n");
  printf("Enter a set to test validation function> ");
  get_set(set_one);  putchar('\n');
  print_set(set_one);
  if (is_set(set_one))
    printf(" is a valid set\n");
  else
    printf(" is invalid\n");
  printf("Enter a single character, a space, and a set> ");
  while(isspace(ele = getchar())) /* gets first character after whitespace */
    ;
  get_set(set_one);
  if (is_set(set_one)) {
    printf("\n%c ", ele);
    if (is_element(ele, set_one))
      printf("is an element of ");
    else
      printf("is not an element of ");
    print_set(set_one);
  }
  else
    printf(" What you entered is NOT a valid set!\n");
  printf("\nEnter two sets to test set_union and intersection> ");
  get_set(set_one);
  get_set(set_two);
  if ( is_set(set_one) && is_set(set_two) ) {
    printf("\nThe union of ");  print_set(set_one);
    printf(" and "); print_set(set_two); printf(" is ");
    print_set(set_union(set_result, set_one, set_two));
    printf("\n and their intersection is :");
    strcpy(set_result, "");  // Important step, to start with a clear result string !
    print_set(intersection(set_result, set_one, set_two));
  }
  else printf("One of the sets you gave is not a valid set!");
  putchar('\n');
  return (0);
}

/*Determines if set is empty. If so, returns 1; if not, returns 0.*/
int is_empty(const char *set)
{
  return (set[0] == '\0');
}

/*Determines if ele is an element of set.*/
int is_element(char ele, const char *set)
{
  if (is_empty(set))
    return FALSE;
  else if (set[0] == ele)
    return TRUE;
  else
    return is_element(ele, &set[1]);
}

/* Determines if string value of set represents a valid set (no duplicate elements) */
int is_set (const char *set)
{
  if (is_empty(set))
    return TRUE;
  else if (is_element(set[0], &set[1]))  //duplicate element, so not a valid set!
    return FALSE;
  else
    return is_set(&set[1]);
}

/* Determines if value of sub is a subset of value of set. */
int is_subset(const char *sub, const char *set)
{
  if (is_empty(sub))
    return TRUE;
  else if (!is_element(sub[0], set))
    return FALSE;
  else
    return is_subset(&sub[1], set);
}

/* Finds the union of set1 and set2.
*  Precond: size of result array is at least SETSIZ; set1 and set2 are valid sets of characters/digits */
char * set_union(char *result, const char *set1, const char *set2)
{
  char temp[SETSIZ]; /* local variable to hold result of call to set_union embedded in sprintf call */
  if (is_empty(set1))
    strcpy(result, set2);
  else if (is_element(set1[0], set2))  //is the specific element of 1st set also a member of 2nd set?
    set_union(result, &set1[1], set2); // then do not bother to include it in the union, skip it
  else
    sprintf(result, "%c%s", set1[0], set_union(temp, &set1[1], set2)); // else include it and continue
  return (result);
}

/* Finds the intersection of set1 and set2 (their common elements)
*  Precond: size of empty result array is at least SETSIZ; set1 and set2 are valid sets of characters/digits */
char *intersection( char *result, const char *set1, const char *set2)
{
  if( is_empty(set1) )  //any empty sets?
    strncat(result,"",1);  // no common elements, intersection is just an empty set
  else if( !is_element(set1[0], set2) )   //is the specific element of 1st set NOT a member of 2nd set?
    intersection(result, &set1[1], set2); // then do not bother to include it in the intersection, skip it
  else {
    strncat(result,&set1[0],1);
    intersection(result, &set1[1], set2);
  }
  return result;
}

/* Displays a string so that each pair of characters is separated by a comma and a space.*/
void print_with_commas(const char *str)
{
  if (strlen(str) == 1)
    putchar(str[0]);
  else {
    printf("%c, ", str[0]);
    print_with_commas(&str[1]);
  }
}

/* Displays a string in standard set notation.  e.g. print_set("abc") outputs {a, b, c} */
void print_set(const char *set)
{
  putchar('{');
  if (!is_empty(set))
    print_with_commas(set);
  putchar('}');
}

/* Gets a set input as a string with brackets (e.g., {abc}) and strips off the brackets. */
char * get_set(char *set)
{
  char inset[SETSIZ];
  scanf("%s", inset);
  strncpy(set, &inset[1], strlen(inset) - 2); /* get rid of 1st and last entered char, even if they were not {,} */
  set[strlen(inset) - 2] = '\0';
  if( is_set(set) )
    return (set);
  else {
    printf("You entered some duplicate characters, so it is not valid set.");
    return "" ;  // return empty set instead
  }
}

// gcc -Wall -o 9.5exercise.programming1 9.5exercise.programming1.c 
