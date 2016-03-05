#include <stdio.h>
int main(void)
{
	FILE *inp;		/* pointer to input file */
	FILE *outp;		/* pointer to ouput file */
	double item;		
	int input_status; 	/* status value returned by fscanf */
	int count=0;		/* data successfuly scanned from input file */
/* Prepare files for input or output */
	inp = fopen("6.1ep1indata.txt", "r");
	outp = fopen("6.1ep1outdata.txt", "w");
/* Read each item, format it, and write it */
	input_status = fscanf(inp, "%lf", &item);
	while (input_status == 1) 
	{
		count++;
		fprintf(outp, "%.2f\n", item);
		input_status = fscanf(inp, "%lf", &item);
	}
	fprintf(outp, "%d items read and written\n", count);
/* Close the files */
	fclose(inp);
	fclose(outp);
	return (0);
}
// gcc -Wall -o 6.1ep1 6.1ep1.c
