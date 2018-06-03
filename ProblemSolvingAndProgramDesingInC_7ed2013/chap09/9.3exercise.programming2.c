/* Write a recursive function fast_fib to compute a pair of Fibonacci numbers, F(n + 1) and F(n).
Function fast_fib should make only one recursive call.
Algorithm
if n is 1: The pair to send back is 1, 1.
else
  Use fast_fib to compute F( n ) and F(n − 1).
  The pair to send back is [F( n ) + F(n − 1)], F( n ). */
#include <stdio.h>

long int fibonacci(int n)  /* a more compact implementation than the book Example 9.5(Figure 9.13) */
{
  if (n < 2) return 1;
  else return ( fibonacci(n - 2) + fibonacci(n - 1) );
}
/* I am not sure what the book means when mentions to return a pair, I tried initally to use pointer parameters
* but could not manage to produce correct results, so I did it this way with a normal return value, and 1 recusrsive call */
unsigned long fast_fib(int n, int fn, int fn1)
{
  if (n < 2) return fn;
  else return fast_fib(n-1, fn + fn1, fn );  //only one recursion 
}

int main()
{
  long int fib;
  int fibn=1, fibn1=1;  // the first 2 terms of fibonacci series 1,1,2,3,5,8,13,21,34,55,89,...
  int n;
  char garbage;
  puts("Enter a positive integer larger than 1, for  fibonacci number:");
  do {
    while (scanf("%d", &n) != 1)  //user did not gave a number as input?
    {
      printf("Please enter a number, not characters!\n");
      do scanf("%c", &garbage); while (garbage != '\n'); //absorb extra characters
    }
    if(n < 2)    // user gave a number, but not in indicated accepted values?
    {
      printf("%d is not larger than 1.\n", n);
      printf("Please enter a number in the allowed range >1 \n>");
    }
  } while(n < 1);
  fib = fibonacci(n);
  printf(" fib is %ld \n", fib);
  fib = fast_fib(n, fibn, fibn1);
  printf(" and with single-recursion method, fib is also %ld  \n", fib);
  return 0;
}
