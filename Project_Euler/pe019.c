/**
 * PE 019: Counting Sundays. At least I got this one.
 *
 * real   0m0.019s
 * user   0m0.002s
 * sys    0m0.002s
 */

#include <stdio.h>

int main(void) 
{
    // February gets +1 on all years in this problem except for 1900, but that
    // date is actually outside the range we're considering.
    int days[] = {31, // January
                  28, // February
                  31, // March
                  30, // April
                  31, // May
                  30, // June
                  31, // July
                  31, // August
                  30, // September
                  31, // October
                  30, // November
                  31  // December
    };

    // Start with 01/01/1900 but total isn't updated until at least 01/01/1901.
    // This is 1-indexed so we have to use days[index-1] but easier for me.
    int day = 1;
    int month = 1;
    int year = 1900;
    int dayOfWeek = 1; // goes from 1-7, 1=Monday, 7=Sunday
    int total = 0;

    do {
        // First, adjust dates. E.g., dayOfWeek always updates.
        dayOfWeek++;
        if (dayOfWeek > 7) {
            dayOfWeek = 1;
        }

        if (year % 4 == 0 && year != 1900) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }

        if (month == 12 && day == 31) {
            day = 1;
            month = 1;
            year++;
        } 
        else if (day == days[month-1]) {
            day = 1;
            month++;
        } else {
            day++;
        }

        // Now check if we should track this.
        if (year > 1900 && dayOfWeek == 7 && day == 1) {
            printf("day/month/year = %d/%d/%d\n", day,month,year);
            total++;
        }
    } while (!(year==2000 && month==12 && day==31));

    printf("%d\n",total);
}
