/* Write a recursive function count_digits that counts all the digits in a string.*/
#include <stdio.h>
#include <ctype.h>
#define LINE_LENGTH 80
int countDigits(const char *line);

int main(void)
{
  char line[LINE_LENGTH]; /* string to be processed */
  int digitCount;
  printf("Enter up to %d characters.\n", LINE_LENGTH-1);
  fgets(line, LINE_LENGTH, stdin);            /* read in the string */
  digitCount = countDigits(line);
  printf("The number of digits in\n\"%s\" is %d\n",line, digitCount);
  return (0);
}
/* Counts the number of digits existing in string str. */
int countDigits(const char *str)
{
  int ans;
  if (str[0] == '\0')   /* simple case */
    ans = 0;
  else if ( isdigit(str[0]) )         /* redefine problem using recursion */
    ans = 1 + countDigits(&str[1]);
  else
    ans = countDigits(&str[1]);
  return (ans);
}
// gcc -Wall -o 9.1exercise.programming1 9.1exercise.programming1.c
