#define A_SIZE 10
#define SENTINEL -1.0  /* input of value -1 will signal the end of input. Value -1.0 will not be stored */
#include <stdio.h>
void  fill_to_sentinel(int dbl_max, double sentinel, double dbl_arr[], int *dbl_sizep);

int	main(void)
{
  double arr[A_SIZE];
  int in_use, i;
  printf("Type %d floating numbers to fill an array, type Ctrl+D or enter value %.1f to stop input\n", A_SIZE, SENTINEL);
  fill_to_sentinel(A_SIZE, SENTINEL, arr, &in_use);
  printf("List of data values\n");
  for (i = 0; i < in_use; ++i)
    printf("%13.3f\n", arr[i]);
  return (0);
}

// gcc -Wall -std=c11 -o 7.10example 7.10example.fill_to_sentinel.c 7.10example.main.c
