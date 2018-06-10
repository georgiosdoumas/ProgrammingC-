/* Create a thread and update a shared resource from two different threads */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void* thread_example(void* argument); /* Thread function prototype */
int data;                      /* Global share data */
pthread_mutex_t lock;          /* Thread mutex lock */

int main(void)
{
  pthread_t tid;                /* Thread ids */
  int loop;                     /* Loop count */
/* Display the primary thread id */
  printf ("Primary Thread Started, ID %u\n", pthread_self());
  data = 0;     /* Initialize the global share data */
/* Initialize the mutex lock */
  if (pthread_mutex_init (&lock, NULL) != 0)
    printf ("Error Initializing The Mutex Lock\n");
/* Create a new thread */
  if (pthread_create (&tid, NULL, thread_example, NULL) != 0)
    printf ("Error Creating The Thread\n");
  sleep (1);      /* Wait for the created thread to begin executing */
  for(loop = 0; loop < 5; loop++)
  {
    /* Lock the mutex, update the data, unlock the mutex */
    if(pthread_mutex_lock (&lock) != 0)
      printf ("Error Locking Mutex\n");
    data++;
    /* Display the loop counter and updated data value */
    printf("Primary Thread Writing Loop %d Data %d\n", loop, data);
    if(pthread_mutex_unlock (&lock) != 0)
      printf ("Error Unlocking Mutex\n");
    sleep (1);
  }
  if( pthread_join(tid, NULL) != 0 )  /* Wait for the created thread to complete */
    printf ("Failed Join\n");
  printf("Primary Thread Stopped\n");
  return (0);
}

void* thread_example (void* argument)
{
  int loop; /* Loop counter */
  printf ("Created Thread Started, ID %u\n", pthread_self());
  sleep (1);    /* Wait for the primary thread to write first */
  for (loop = 0; loop < 4; loop++)
  {
    /* Lock the mutex, update the data, unlock the mutex */
    if (pthread_mutex_lock (&lock) != 0)
      printf ("Error Locking Mutex\n");
    data++;
    /* Display the loop counter and updated data value */
    printf ("Created Thread, Writing Loop %d Data %d\n", loop, data);
    if (pthread_mutex_unlock (&lock) != 0)
      printf ("Error Unlocking Mutex\n");
    sleep (1);
  }
  printf ("Created Thread Stopped\n");
  return (NULL);
}

// gcc -Wall -o 14.4figure14.8thread 14.4figure14.8thread.c -lpthread
