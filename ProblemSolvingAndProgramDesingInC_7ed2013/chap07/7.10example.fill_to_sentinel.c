/*  Gets data to place in dbl_arr until value of sentinel is encountered in the input.
   Returns number of values stored through dbl_sizep.
   Stops input prematurely if there are more than dbl_max data values before the sentinel or if invalid data is encountered.
   sentinel and dbl_max are defined and dbl_max is the declared size of dbl_arr
 */
#include <stdio.h>
void  fill_to_sentinel(int dbl_max, double sentinel, double dbl_arr[], int *dbl_sizep)
{
  double data;
  int i = 0, status;
  /** status = scanf("%lf", &data); //for successful reading returns 1
  while (status == 1 && data != sentinel && i < dbl_max)
  {
    dbl_arr[i] = data;
    ++i;
    status = scanf("%lf", &data);
  } **/  // This was the books approach. Here is mine :
  do {
    status = scanf("%lf", &data);
    if(status == 1 && data != sentinel) dbl_arr[i++] = data;
  } while (status == 1 && data != sentinel && i < dbl_max); 
  /* Continuing as the book now */
  if (status != 1)
  {
    printf("\n*** Error in data format ***\n");
    printf("*** Using first %d data values ***\n", i);
  }
  else if (data != sentinel)
  {
    //printf("\n*** Error: too much data before sentinel ***\n"); //With my method, user doesn't have a chance to enter more data
    printf("Thank you for typing all values \n"); // now this message is appropriate
    printf("*** Using first %d data values ***\n", i);
  }
  *dbl_sizep = i;
}
