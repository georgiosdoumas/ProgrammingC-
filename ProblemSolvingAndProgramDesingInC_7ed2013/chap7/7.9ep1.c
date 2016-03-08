/* Exercise programming 1 page 427  
* Scans revenue figures for one year and stores them in a table organized
* by unit and quarter. Displays the table and the annual totals for each
* unit and the revenue totals for each quarter */
#include <stdio.h>
#define REVENUE_FILE "7.9revenue.txt"       /* name of revenue data file */
#define NUM_UNITS 5
#define NUM_QUARTERS 4
typedef enum {summer, fall, winter, spring}  quarter_t;
typedef enum {emerg, medic, oncol, ortho, psych} unit_t;
int scan_table(double revenue[][NUM_QUARTERS], int num_rows);
void sum_rows(double row_sum[], double revenue[][NUM_QUARTERS], int num_rows);
void sum_columns(double col_sum[], double revenue[][NUM_QUARTERS], int num_rows);
void display_table(double revenue[][NUM_QUARTERS], const double unit_totals[], const double quarter_totals[], int num_rows);
void initialize(double revenue[][NUM_QUARTERS], int num_rows, double value);
/* Insert function prototypes for any helper functions. */
void display_quarter(quarter_t quarter);
void display_unit(unit_t u);
int whole_thousands(double number);
int main(void)
{
    double revenue[NUM_UNITS][NUM_QUARTERS]; /* table of revenue */
    double unit_totals[NUM_UNITS];          /* row totals */
    double quarter_totals[NUM_QUARTERS];       /* column totals */
    int status;
    status = scan_table(revenue, NUM_UNITS);
    if (status == 1) 
     {
        sum_rows(unit_totals, revenue, NUM_UNITS);
        sum_columns(quarter_totals, revenue, NUM_UNITS);
        display_table(revenue, unit_totals, quarter_totals,NUM_UNITS);
     }
    return (0);
}
void sum_rows(double row_sum[], double revenue[][NUM_QUARTERS], int num_rows)
{
    int divison;
    quarter_t quarter;
    for (divison = 0; divison < num_rows; ++divison) /* nom_rows will normally run through the 5 divisions of the hospital */
     {
        row_sum[divison]=0.0;        /* Initial sum for each of the 5 hospital divisions,we will add the 4 quarter values */
        for (quarter = summer; quarter <= spring; ++quarter) row_sum[divison] += revenue[divison][quarter];
     }
}
void sum_columns(double col_sum[], double revenue[][NUM_QUARTERS], int num_units)
{
    quarter_t season;
    int division;
    for (season=summer;season<=spring;++season) 
     {
        col_sum[season]=0.0;
        for (division=0;division<num_units;++division) col_sum[season]+=revenue[division][season];
     }
}
/* Scans the revenue data from REVENUE_FILE and computes and stores the revenue
*  results in the revenue table. Flags out-of-range data and data format errors.
* Post: Each entry of revenue represents the revenue total for a particular unit and quarter.
*       Returns 1 for successful table scan, 0 for error in scan.
* Calls: initialize() to initialize table to all zeros */
int scan_table(double revenue[][NUM_QUARTERS], int num_rows)
{
    double trans_amt;                   /* transaction amount */
    int trans_unit;                     /* unit number */
    int quarter;                        /* revenue quarter */
    FILE *revenue_filep;            /* file pointer to revenue file */
    int valid_table = 1;            /* data valid so far */
    int status;     /* input status */
    char ch;        /* one character in bad line */
    initialize(revenue, num_rows, 0.0);         /* Initialize table to all zeros */
    /* Scan and store the valid revenue data */
    revenue_filep = fopen(REVENUE_FILE, "r");
    for ( status=fscanf(revenue_filep,"%d%d%lf",&trans_unit,&quarter,&trans_amt); status==3 && valid_table;
          status = fscanf(revenue_filep, "%d%d%lf", &trans_unit, &quarter, &trans_amt) ) 
     {
        if (summer <= quarter && quarter <= spring && trans_unit >= 0 && trans_unit < num_rows) 
         { revenue[trans_unit][quarter] += trans_amt; } 
        else 
         {
            printf("Invalid unit or quarter -- \n");
            printf(" unit is "); display_unit(trans_unit);
            printf(", quarter is "); display_quarter(quarter);
            printf("\n\n");
            valid_table = 0;
         }
     }
    if (!valid_table) { status = 0; }   /* error already processed */
    else if (status == EOF) { status = 1;}  /* end of data without error */
    else        /* data format error */
    {
        printf("Error in revenue data format. Revise data.\n");
        printf("ERROR HERE >>> ");
        for (status=fscanf(revenue_filep,"%c",&ch);status==1 && ch!='\n';status=fscanf(revenue_filep,"%c",&ch))
            printf("%c", ch);
        printf(" <<<\n");
        status = 0;
    }
    return (status);
}
/* Stores value in all elements of revenue.
* Pre: value is defined and num_rows is the number of rows in revenue.
* Post: All elements of revenue have the desired value. */
void initialize(double revenue[][NUM_QUARTERS], int num_rows, double value)
{
    int row;
    quarter_t quarter;
    for (row = 0; row < num_rows; ++row)
        for (quarter = summer; quarter <= spring; ++quarter) revenue[row][quarter] = value;
}
/* Displays the revenue table data (rounded to whole thousands) in table form along with the row and column sums (also rounded)
* Pre: revenue, unit_totals, quarter_totals, and num_rows are defined.
* Post: Values stored in the three arrays are displayed rounded to whole thousands. */
void display_table(double revenue[][NUM_QUARTERS], const double unit_totals[], const double quarter_totals[],int num_rows)
{
    unit_t unit;
    quarter_t quarter;
    /* Display heading */
    printf("%34cREVENUE SUMMARY\n%34c---------------\n\n", ' ', ' ');
    printf("%5s%12c", "Unit ", ' ');
    for (quarter = summer; quarter <= spring; ++quarter)
    {
        display_quarter(quarter);
        printf("%8c", ' ');
    }
    printf("TOTAL*\n");
    printf("--------------------------------------------------------------------------------\n");
    /* Display table */
    for (unit = emerg; unit <= psych; ++unit) 
    {
        display_unit(unit);
        printf(" ");
        for (quarter = summer; quarter <= spring; ++quarter)  printf("%14.2f", revenue[unit][quarter]);
        printf("%11d\n", whole_thousands(unit_totals[unit]));
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("TOTALS*");
    for (quarter = summer; quarter <= spring; ++quarter) printf("%15d", whole_thousands(quarter_totals[quarter]));
    printf("\n\n*in thousands of dollars\n");
}
void display_quarter(quarter_t quarter)
{
    switch (quarter) 
    {
        case summer: printf("Summer "); break;
        case fall: printf("Fall ");    break;
        case winter: printf("Winter "); break;
        case spring: printf("Spring "); break;
        default: printf("Invalid quarter %d", quarter);
    } 
}
void display_unit(unit_t division)
{
    switch (division)
    {
        case emerg: printf("Emergency   "); break;
        case medic: printf("Medicine    "); break;
        case oncol: printf("Oncology    "); break;
        case ortho: printf("Orthopedics "); break;
        case psych: printf("Psychiatry  "); break;
        default: printf("Invalid Division %d ",division);
    }
}
/* Return how many thousands,after rounding, are in a number */
int whole_thousands(double number)
{
    return (int)((number + 500)/1000.0);
}
