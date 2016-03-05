#include <stdio.h>
#define EFFICIENCY 0.90
#define G 9.80		/* gravity constant */
#define MofCM 1000  /* mass of 1 cubic meter of water */
/* w=mgh , work = mass*gravityconst*height */
/* power is work per second */
int main (void)
{
	double cubm_per_sec,megawatts;
	int height;
	printf("Give height of hydroelectric dam,in meters (integer): ");
	scanf("%d",&height);
	printf("How many cubic-meters/sec will flow from the top to the bottom? ");
	scanf("%lf",&cubm_per_sec);
	megawatts = (EFFICIENCY * cubm_per_sec * MofCM * G * height)/1000000.0;
	printf("Power of %.2f  MegaWatts will be produced\n",megawatts);
	return 0;
}
