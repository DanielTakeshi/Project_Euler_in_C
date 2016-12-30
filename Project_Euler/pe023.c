/**
 * PE 023: Non-Abundant Sums. This is brute force, though I used the stdlib
 * bsearch method. Very nice! It still runs pretty fast, less than a second:
 *
 * real   0m0.365s
 * user   0m0.337s
 * sys    0m0.004s
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumOfDivisors(int n) 
{
    int sumOfDivisors = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sumOfDivisors += i;
            if (i != sqrt(n)) {
                sumOfDivisors += (n/i); // must add larger term
            }
        }
    }
    return sumOfDivisors;
}


int cmpfunc(const void * a, const void * b) 
{
    return ( *(int*)a - *(int*)b );
}


int main(void) 
{
    int abundantNums[28123];
    int num = 0;
    for (int i = 12; i < 28123; i++) {
        if (sumOfDivisors(i) > i) {
            abundantNums[num] = i;
            num++;
        }
    }
    printf("total abundant nums: %d\n", num);

    int sum = 0;
    for (int i = 1; i < 28123; i++) {
        // if (i % 100 == 0) printf("i=%d\n", i);
        int canBeWritten = 0;

        for (int j = 0; j < num; j++) {
            int abundN1 = abundantNums[j];
            if (abundN1 >= i) break;
            int abundN2 = i - abundN1;

            int *item = (int*) bsearch(&abundN2, abundantNums, num, sizeof (int), cmpfunc);
            if (item != NULL) {
                canBeWritten = 1;
                break;
            }
        }

        if (canBeWritten == 0) sum += i;
    }

    printf("sum = %d\n", sum);
}
