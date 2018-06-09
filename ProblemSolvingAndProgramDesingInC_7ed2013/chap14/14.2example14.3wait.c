// Implementing a full working example based on what is mentioned in example 14.3

#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(void)
{
  pid_t pid, pidw;
  int childStatus, number=-2;
  printf("I am the parent process with ID: %d\n", getpid());
  printf("Lets create a child process with fork...\n");
  pid = fork();
  if (pid < 0)  /* Code executed in the parent process only if unsuccessful */
    printf("  Error on attempting to fork and create a child process!\n");
  else if (pid == 0)
  {   /* Code executed in the child process only if successful */
    printf("    Report form inside the child process: Child ID %d\n", getpid());
    printf("    Exclusive output from child process here! \n");
    printf("    While in the child proc, lets do a simple calculation.\n");
    int num;
    printf("\tEnter 2 integers:");
    scanf("%d", &number);
    scanf("%d", &num);
    printf("\t Doubling them you get %d and from local variable %d\n", 2*number, 2*num);
  }
  else
  { /* Code executed in the parent process only if successful */
    pidw = wait (&childStatus); //if we do not do this, we will not even have a chance to enter input in the child process! 
    if (pidw > 0)
      printf ("  --pid we waited for: %d, status %d\n", pidw, WEXITSTATUS(childStatus));
    printf("  Parent ID %d successfuly created Child ID %d\n", getpid(), pid);
    printf("  Exclusive output from parent process here! \n");
    printf("  While in the parent proc, lets do a simple calculation.\n");
    printf("  Give an integer (its current value is %d):", number);  // -2 is the current value! 
    scanf("%d",&number);
    printf("  Tripling it you get %d\n", 3*number);
  }
  printf("  Where will this get print? From both parent and child %d!\n", getpid());
  return 0;
}

// gcc -Wall -o 14.2example14.3wait 14.2example14.3wait.c
