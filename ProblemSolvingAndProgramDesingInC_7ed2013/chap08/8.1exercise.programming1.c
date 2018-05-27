/* Write a program that takes a word less than 25 characters long and prints a statement like this:
fractal starts with the letter f
Have the program process words until it encounters a “word” beginning with the character '9' . */

#include<stdio.h>
#define WORDSIZE 11 /* if you edit this value, remember to edit also the line of scanf */
//#define E 9   //not helpful
int main()
{
  char word[WORDSIZE] = " ";
  int nw = 0;   // number of words given as input
  do {
    printf("Enter a word (%d characters or less),or type 9 to finish input:",WORDSIZE);
    scanf("%10s",word); /*there does not seem to be a way to use the WORDSIZE-1 instead of a pure number */
    //scanf("%s",word); //this would be bad, i.e. for a WORDSIZE+8 char input word we get core dumped at execution
    if (word[0] == '9') break;  // is there a way to use the preprocessor here,like: if (word[0]=='E') ??
    else nw++;
    printf("%s starts with %c \n",word,word[0]);
  } while (1);
  printf("Thanks for giving %d words \n",nw);
  return 0;
}

// gcc -Wall -o 8.1exercise.programming1 8.1exercise.programming1.c
