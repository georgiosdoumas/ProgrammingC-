#include <stdio.h>
#define RATE_PER_MILE 0.35  /* dollars to pay per mile traveled */
int main (void)
{
	double start , end , distance;
	printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
	printf("Enter beginning odometer reading=> ");
	scanf("%lf",&start);
	printf("Enter ending odometer reading=> ");
	scanf("%lf",&end);
	distance = end - start ;   /*at this point we trust the user that end>start */
	printf("You traveled %.1f miles.",distance); 
	printf("At  $%.2f per mile,\n",RATE_PER_MILE);
	printf("your reimbursement is $%.2f \n", distance * RATE_PER_MILE );
	return (0);
}
