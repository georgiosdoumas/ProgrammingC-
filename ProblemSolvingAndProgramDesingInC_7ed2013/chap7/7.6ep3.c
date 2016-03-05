/* Exercise programming 3 , page 406 */
#include <stdio.h>
int get_index_of_min(const double arr[], int first, int last)  
{
	int i, position_of_min = first;
	for (i = first; i <= last; ++i) 
	  if(arr[i] < arr[position_of_min]) position_of_min = i;
	return (position_of_min);
}
void select_sort(double list[], int listsize)
{
	int running_index, index_of_min;
	double temp;
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
void display_arr(double arr[], int arrsize)
{
	int i;
	for(i=0;i<arrsize;i++) printf("%6.2f ",arr[i]);
	printf("\n");
}
int main(void)
{
	double data1[]={50.1,50.1,47.2,23.7,12.78,9.65,5.44,1.29};
	double data2[]={7.1,28.22,18,37.6,42.1,42.1,4.23};
	display_arr(data1,8); display_arr(data2,7); 
	select_sort(data1, 8);
	select_sort(data2, 7);
	display_arr(data1,8); display_arr(data2,7); 
	return 0;
}	
