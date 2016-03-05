/* programming project 12 , page 372 */
#include <stdio.h>
#define DIVISOR 64
int main(void)
{
	int spacechar=' ';
	char inputchar; 
	do {
		int linelettercount=0,linechecksum=0;
		printf("Type your line (end it with period),to find its checksum\n"); 
		printf("(finish by giving a line with only . typed): ");
		do
		 {
			scanf("%c",&inputchar);
			linelettercount++;
			if (inputchar=='.' && linelettercount==1)  return 0; /*no need to process the last . line */
			linechecksum+=inputchar;
		  } while (inputchar!='.');
		linechecksum=linechecksum%DIVISOR;
		linechecksum+=(int)spacechar;
		printf("Checksum for the processed line: %d ,character \"%c\" \n",linechecksum,linechecksum);
	   } while(scanf("%c",&inputchar)); /*absorb the leftover \n of the finished line,before going to the next */
	return 0;
}	
