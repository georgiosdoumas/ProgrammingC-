/* Programming exercise 1 , page 414 */
#include <stdio.h>
int main(void)
{
    typedef enum { Jan,Feb,March,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec } month_t;
    month_t current_month;
    int month=0;
    while(month<1 || month>12) 
    {
        printf("Enter number (from 1-12) of current month: ");
        scanf("%d",&month);
        if(month<1 || month>12) printf("***Invalid value for month %d ***\n",month);
    }
    current_month=month-1;
    if (current_month == 0) printf("Happy New Year\n");
      else if (current_month == 5) printf("June , summer begins\n");
    switch (current_month) 
    {
        case Sep: printf("September, back to school\n");
        case 11: printf("December, Marry Christmas!\n");
        default: printf("An ordinary month.");
    }
    return 0;
}
