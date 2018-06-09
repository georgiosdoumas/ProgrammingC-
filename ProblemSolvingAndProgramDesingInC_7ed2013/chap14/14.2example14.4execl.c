#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(void)
{
  int number, childStatus;
  pid_t pid;
  printf("I am the parent process with ID: %d\n", getpid());
  printf("Lets create a child process with fork...\n");
  pid = fork();
  printf ("  Parent process after fork has an arithmetic task...\n"); // Beware: this appears 2 times!
  if (pid == 0)
    execl ("14.2example14.4newprog.exe", "14.2example14.4newprog.exe", NULL);
  else {
    pid = wait (&childStatus);  // again this is needed
    printf ("Parent process after if statement ...\n");
    printf("Enter an integer and I will triple it:");
    scanf("%d", &number);
    printf("Your number tripled is: %d \n", 3*number);
  }
  return 0;
}

// gcc -Wall -o 14.2example14.4newprog.exe 14.2example14.4newprog.c
// gcc -Wall -o 14.2example14.4execl 14.2example14.4execl.c
