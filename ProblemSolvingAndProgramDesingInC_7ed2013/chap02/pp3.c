#include <stdio.h>
int main (void)
{
	double elapsed_time_hrs,temperature;
	int hh=0,mm=0;
	printf("To estimate the temperature in the freezer,since power failed,\n");
	printf("enter the time that passed in hh:mm format> ");
	scanf("%d:%d",&hh,&mm);  /* acceptable input: 06:31 ,5:51 ,4 (4 hrs) ,0:50 , :4 (4 mins) */
	elapsed_time_hrs = hh + mm/60.0;
	temperature = ((4*elapsed_time_hrs * elapsed_time_hrs)/(elapsed_time_hrs + 2)) - 20;
	printf("Current temperature is %.2f Celsious.\n",temperature);
	return 0;
}
