/* Finds the index of the string that comes first alphabetically in
* elements min_sub..max_sub of list
* Pre: list[min_sub] through list[max_sub] are of uniform case;
       max_sub >= min_sub
*/
#include <string.h>
#include <stdio.h>
int alpha_first(char *list[], int min_sub, int max_sub)
{
  int first, i;
  first = min_sub;
  for (i = min_sub + 1; i <= max_sub; ++i)
  if (strcmp(list[i], list[first]) < 0)  first = i;
  return (first);
}
/* Orders the pointers in array list so they access strings
* in alphabetical order
* Pre: first n elements of list reference strings of uniform case;
       n >= 0
*/
void select_sort_str(char *list[],  int n)
{
  int fill,
  index_of_min;
  char *temp;
  for(fill = 0; fill < n - 1; ++fill)
  {
    index_of_min = alpha_first(list, fill, n - 1);
    if (index_of_min != fill)
    {
      temp = list[index_of_min];
      list[index_of_min] = list[fill];
      list[fill] = temp;
    }
  }
}
