/* Exercise programming 1 , page 406 */
#include <stdio.h>
int get_index_of_min(const int arr[], int first, int last)  
{
	int i, position_of_min = first;
	for (i = first; i <= last; ++i) 
	  if(arr[i] < arr[position_of_min]) position_of_min = i;
	return (position_of_min);
}
void select_sort(int list[], int listsize)
{
	int running_index, temp, index_of_min;
	for (running_index = 0; running_index < listsize-1; ++running_index) 
	{
		index_of_min = get_index_of_min(list, running_index, listsize-1); 
		if (running_index != index_of_min) 
		{
			temp = list[index_of_min];
			list[index_of_min] = list[running_index];
			list[running_index] = temp;
		}
	}
}
void display_arr(int arr[], int arrsize)
{
	int i;
	for(i=0;i<arrsize;i++) printf("%d ",arr[i]);
	printf("\n");
}
int main(void)
{
	int data1[]={8,53,32,54,74,3}; //How to read array from a file?? TO_DO 
	int data2[]={7,28,18,37,42,42};
	display_arr(data1,6); 
	display_arr(data2,6); 
	select_sort(data1, 6);
	select_sort(data2, 6);
	display_arr(data1,6); display_arr(data2,6); 
	return 0;
}
