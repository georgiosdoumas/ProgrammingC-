/* Maintains 2 orderings of a list of applicants: the original ordering of the data,
* and an alphabetical ordering accessed through an array of pointers. */
#include <stdio.h>
#include <string.h>
#define STRSIZ 20 /* maximum string length for entered names */
#define MAXAPP 10 /*maximum number of applications accepted */
int alpha_first(char *list[], int min_sub, int max_sub);
void select_sort_str(char *list[], int n);

int main(void)
{
  char applicants[MAXAPP][STRSIZ];
  char *alpha[MAXAPP];
  int num_app=0, i;
  char one_char;
  printf("Enter number of applicants (1 . . %d)\n> ", MAXAPP);
  do {
    while (scanf("%d", &num_app) != 1)
    {
      printf("Please enter a number, not characters!\n");
      do scanf("%c", &one_char); while (one_char != '\n');
    }
    if(num_app > MAXAPP || num_app <1)
    {
      printf("%d is more than the allowed maximum number we can proccess.\n", num_app);
      printf("Please enter a number in the allowed range (1.. %d) \n>", MAXAPP);
    }
  } while(num_app > MAXAPP || num_app <1);
  do  // to absorb any spaces that may have been typed after the number, and also absorb the \n
    one_char = getchar(); //scanf("%c", &one_char);
  while (one_char != '\n');
  printf("Enter names of %d applicants on separate lines in the order in which they applied\n", num_app);
  printf("Names longer than %d will be truncated! \n", STRSIZ );
  for (i = 0; i < num_app; ++i)
  {
    /* fgets() reads in at most one less than size characters from stream and stores them into the buffer pointed to  by
       s.   Reading stops after an EOF or a newline.  If a newline is read, it is stored into the buffer.  A terminating
       null byte ('\0') is stored after the last character in the buffer. */
    fgets(applicants[i], STRSIZ, stdin);  // read STRSIZ-1 characters at maximum
    if(strlen(applicants[i]) < STRSIZ-1)
       applicants[i][strlen(applicants[i])-1]='\0';   //substitute '\n' with '\0'
    else if (applicants[i][strlen(applicants[i])-1] == '\n')
    {
      puts("  That was a long name! ");   //comment it out for non-debug
      applicants[i][strlen(applicants[i])-1]='\0';
    }
    else
    {
      puts("  That was a long name! It will be truncated.");  //comment it out for non-debug
      do one_char = getchar(); while (one_char != '\n');  //discard extra characters, truncate name
    }
  }
  for (i = 0; i < num_app; ++i)
    alpha[i] = applicants[i]; /* copies ONLY address */
  select_sort_str(alpha, num_app);
  printf("\n\n%-30s%5c%-30s\n\n", "Application Order", ' ', "Alphabetical Order");
  for (i = 0; i < num_app; ++i)
    printf("%-30s%5c%-30s\n", applicants[i], ' ', alpha[i]);
  return(0);
}
// gcc -Wall -o 8.5example7 8.5example7.functions.c 8.5example7.main.c

