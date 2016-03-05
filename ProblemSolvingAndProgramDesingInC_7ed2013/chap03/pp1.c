#include <stdio.h>
#include <math.h>
int main(void)
{
	double down_payment,total_car_price,annual_interest,mi,monthly_pay;
	int months_paying;
	printf("What is the total price of the car? $ ");
	scanf("%lf",&total_car_price);
	printf("How many months do you want the payment period to be? (eg: 36 , 48 ...) ");
	scanf("%d",&months_paying);
	printf("Give the annual interest rate that your bank will ask for the loan (eg 12%%) :");
	scanf("%lf%%",&annual_interest);
	mi=annual_interest/(12.0*100);
	printf("How much do you have now for the down-payment? $: ");
	scanf("%lf",&down_payment);
	printf("So you must borrow %.2f$ and you will be paying it over a period of %d months.\n",total_car_price-down_payment,months_paying);
	monthly_pay = mi*(total_car_price-down_payment) / (1 - pow( 1 + mi, -months_paying ) );
	printf("You will have to pay %.2f$ per month.Can you afford it?\n",monthly_pay);
	return 0;
}
// gcc -Wall -o pp01 pp01.c -lm 
// where the lm is for linking to math library
