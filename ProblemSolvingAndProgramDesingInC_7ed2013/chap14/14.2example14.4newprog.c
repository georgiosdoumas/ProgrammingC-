// just a simple program to be executed from inside the child proc 
#include <stdio.h>

 int main(void)
 {
   char name[20];
   printf("\tEnter your name:");
   scanf("%19s", name);
   printf("\tHello %s !\n", name);
   return 0;
 }

// gcc -Wall -o 14.2example14.4newprog.exe 14.2example14.4newprog.c
