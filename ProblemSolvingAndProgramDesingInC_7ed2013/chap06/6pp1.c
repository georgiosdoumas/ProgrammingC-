/*programming project 1 , page 364*/
#include <stdio.h>
#define PAPER50 50
#define PAPER20 20
#define PAPER10 10
int dispenser(int * r,int b);
int main(void)
{
	int money,numof50,numof20,numof10;
	int goodscanf=0;
	printf("Enter amount of money to dispense (in PAPERs of %d,%d and %d): ",PAPER50,PAPER20,PAPER10);
	do
	{
		char garbagechar;
		goodscanf=scanf("%d",&money);
		if(goodscanf==0) 
		 {
			printf("Invalid input.Give integer number for amount of money: ");
			do { scanf("%c",&garbagechar); } while(garbagechar!='\n'); continue;
		 }
		if((money%10)!=0) 
		 {printf("%d is not a multiple of 10$.Please enter a valid amount: ",money); goodscanf=0;continue;}
		else break;	
	} while ( goodscanf != 1);
	numof50=dispenser(&money , PAPER50 );
	numof20=dispenser(&money , PAPER20 );
	numof10=dispenser(&money , PAPER10 );
	printf("You will take %d of 50s , %d of 20s and %d of 10$ papers\n",numof50,numof20,numof10);
	return 0;
}
int dispenser(int * remainder,int base)
{
	int count;
	count=(*remainder) / base;
	*remainder = *remainder % base;
	return count;
}
