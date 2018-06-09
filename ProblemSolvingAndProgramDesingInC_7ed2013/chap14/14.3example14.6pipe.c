// It was not easy to produce a fully working example.
// But it was interesting to test all the possible positions for the:
// if( pipe(filedes) < 0 )
// Commenting out the correct position and uncommenting each of the WRONG places
// we see various ERROR messages, or in a case no message at all.

#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <string.h>

int main(void)
{
  int filedes[2]; //index 0 is for read and index 1 is for write
  char buffer[30] = "initial";
  pid_t pid;
  int childStatus;
  printf("I am the parent process with ID: %d\n", getpid());
  printf("Curent contents of my buffer: -%s- \n",buffer);
  if( pipe(filedes) < 0 )  // The only correct position for this task!!! Before the fork() is called!!!
    printf ("ERROR Creating The Pipe\n");
  printf("Lets create a child process, from which we will alter the buffer\n");
  pid = fork();
  //if( pipe(filedes) < 0 ) //WRONG place to do it, no edit will take place on buffer
    //printf ("ERROR Creating The Pipe\n");
  if (pid < 0)  /* Code executed in the parent process only, if unsuccessful */
    printf("  Error on attempting to fork and create a child process!\n");
  else if (pid == 0) /* Change buffer contents from the child process */
  {
    //if( pipe(filedes) < 0 )  // WRONG place to do it, because parent proc will fail to read
      //printf ("Error Creating The Pipe\n");
    if ( close(filedes[0]) < 0 )  //in child proc, we only want to write
      printf ("\t ERROR Closing The Read File Descriptor\n");
    strcpy(buffer, "New Buffer Contents");
    printf("\tFrom child proc %d : buffer contents edited!\n", getpid());
    if( write(filedes[1], buffer, strlen (buffer)) < 0 )
      printf ("\t ERROR Writing To The Write File Descriptor\n");
    else
      printf("\tEdited contents of buffer <%s> have been passed to fd %d for parent to read.\n", buffer, filedes[1]);
  }
  else  /* Code executed in the parent process only, to read the altered buffer */
  {
    //if( pipe(filedes) < 0 )  //WORNG place to do it, because child prc will fail to edit/write the buffer!
      //printf ("ERROR Creating The Pipe\n");
    pid = wait(&childStatus);
    if (pid > 0)
      printf ("--pid we waited for buffer edits: %d, status %d\n", pid, WEXITSTATUS(childStatus));
    if ( close(filedes[1]) < 0)
      printf (" Error Closing The Write File Descriptor\n");
    if ( read(filedes[0], buffer, sizeof(buffer)) < 0)
      printf (" Error Reading From The Read File Descriptor\n");
    printf("--Curent contents of my buffer: -%s- \n",buffer);
  }
  return 0;
}

// gcc -Wall -o 14.3example14.6pipe 14.3example14.6pipe.c
