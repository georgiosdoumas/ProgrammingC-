/* Modify the fragment in Example 14.2 to print whether the parent process is executing or the child process is executing. */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
  pid_t pid;
  printf("I am the parent process with ID: %d\n", getpid());
  printf("Lets create a child process with fork...\n");
  pid = fork();
  if (pid < 0)
  {   /* Code executed in the parent process only, if fork unsuccessful */
    printf("  Error on attempting to fork and create a child process!\n");
  }
  else if (pid == 0)
  {   /* Code executed in the child process only, if successful */
    printf("    Report form inside the child process: Child ID %d\n", getpid());
    printf("    Exclusive output from child process here! \n");
  }
  else
  { /* Code executed in the parent process only, if successful */
    printf("  Parent ID %d successfuly created Child ID %d\n", getpid(), pid);
  }
  printf("  Where will this get print? From both parent and child %d!\n", getpid());
  return 0;
}

// gcc -Wall -o 14.2example14.2 14.2example14.2.c
