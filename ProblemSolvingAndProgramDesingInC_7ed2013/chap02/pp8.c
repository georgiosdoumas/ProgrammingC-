#include <stdio.h>
#define LOWFLUSH 2  /*consumption in liters for new low-flush toilets */
#define OLDFLUSH 15 /*consumption in liters for old toilets */
#define AVG_DAILY_USE 14 /* estimation for every toilet */
#define COST_NEW 150 /* cost in dollars to install each new toilet */
int main (void)
{
	int population;
	double oldconsumption_daily,watersavings_daily,watercost_liter,total_cost;
	printf("This program will assist you to estimate the reduce in water consumption\n");
    printf("that will be achived by replacing old toilets that need %d liters per use\n",OLDFLUSH);
	printf("and install new toilets,costing %d$ to install and using only %d liters per use\n",COST_NEW,LOWFLUSH);
	printf("Enter the population of your city : ");
	scanf("%d",&population);
	printf("How many $ is the cost of 1 lt of water in your city? ");
	scanf("%lf",&watercost_liter);
	watersavings_daily = (OLDFLUSH-LOWFLUSH) * AVG_DAILY_USE * (population/3.0);
	oldconsumption_daily = OLDFLUSH * AVG_DAILY_USE * (population/3.0);
	total_cost = COST_NEW*(population/3.0);
	printf("Assuming 1 toilet per 3 persons and an avarage use of %d flushes\n",AVG_DAILY_USE);
	printf("the current daily consumption is around %.2f$ \n",oldconsumption_daily);
	printf("With a total cost of installation of %.1f $ , \n",total_cost);
	printf("you can achive %.1f $ of savings per day\n",watersavings_daily);
	return 0;
}
