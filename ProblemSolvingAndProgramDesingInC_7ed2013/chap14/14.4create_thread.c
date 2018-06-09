#include <pthread.h>
#include <unistd.h>  // for sleep()
#include <stdio.h>

void* thr_sub (void* arg); //or do definition of function here

int main(void)
{
  char msg[30] = "message for thread!";
  pthread_t thread_id;
  printf("Lets create a thread\n");
  pthread_create (&thread_id, NULL, thr_sub, msg);
  sleep(1);
  printf ("Main thread after pthread_create()\n");
  printf("ID of thread: %ld \n", thread_id); // not sure if this is OK. Gives very big numbers
  return 0;
}

void* thr_sub (void* arg)
{
  printf("  New thread first executable statement\n");
  printf("  The message received was : %s \n", arg);
  return (NULL);
}

// gcc -Wall -o 14.4create_thread 14.4create_thread.c -lpthread
