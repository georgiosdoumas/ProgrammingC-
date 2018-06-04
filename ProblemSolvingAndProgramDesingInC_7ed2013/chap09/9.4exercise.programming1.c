/* Modify the find_caps function to create a find_digits function that returns
a string consisting of all digit characters in the source string. */
#include<stdio.h>
#include<ctype.h>
#define STRSIZ 50
char * findDigits(char *digits, const char *str)
{
  char restDigits[STRSIZ]; /* caps from remaining str (that starts form str[1]) */
  if (str[0] == '\0')
    digits[0] = '\0'; /* no digits in empty str  */
  else if (isdigit(str[0]))
    sprintf(digits, "%c%s", str[0], findDigits(restDigits, &str[1]));
  else
    findDigits(digits, &str[1]);
  return (digits);
}

int main()
{
  char mydigits[STRSIZ];
  char * moredigits;
  char text[STRSIZ] = "H0w Many D1g1ts  do 7 hav3?";
  printf("Digits in 8r3ak are %s\n", findDigits(mydigits, "8r3ak"));
  moredigits = findDigits(mydigits, text);
  printf(" and in \n %s \n  are %s \n", text, moredigits );
  printf(" Just to be sure we have the modified string : %s \n", mydigits);
  return 0;
}
// gcc -Wall -o 9.4exercise.programming1  9.4exercise.programming1.c
