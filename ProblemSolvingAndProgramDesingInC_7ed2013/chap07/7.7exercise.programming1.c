/* Programming exercise 1 , page 414 
Declare an enumerated type m onth_t and rewrite the following if statement,
assuming that cur_month is type month_t instead of type int . Also, write the
equivalent switch statement.
if (cur_month == 1)
printf("Happy New Year\n");
else if (cur_month == 6)
printf("Summer begins\n");
else if (cur_month == 9)
printf("Back to school\n");
else if (cur_month == 12)
printf("Happy Holidays\n"); */

#include <stdio.h>
int main(void)
{
    typedef enum { Jan = 1, Feb, March, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } month_t;
    month_t current_month;
    int month=0; /* intial value of month is not acceptable so that we can enter the while loop and ask the user to privide a value */
    while(month<1 || month>12) 
    {
        printf("Enter number (from 1-12) of current month: ");
        scanf("%d",&month);
        if(month<1 || month>12) printf("***Invalid value for month %d ***\n",month);
    }
    current_month=month;
    if (current_month == 1) printf("Happy New Year\n");
    else if (current_month == Jun) printf("June , summer begins\n"); /* just to show that we can use Jun instead of 6 */
    else   /* instead of  doing the rest if-else statements, I do partially the switch statement for the remaining cases */
    switch (current_month) 
    {
        case Sep: printf("September, back to school\n"); break;
        case 12: printf("Marry Christmas!\n"); break;
        default: printf(" An ordinary month.\n");
    }
    return 0;
}
