/**
 * PE 021: Amicable Numbers. Huh, this one was easy (well, to do in brute
 * force), I should have done this earlier.
 *
 * real   0m0.059s
 * user   0m0.012s
 * sys    0m0.003s
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int const LIMIT = 10000;

int sumOfDivisors(int n) {
    int sum = 1;
    for (int i = 2; i <= n/sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != sqrt(n)) {
                sum += (n/i);
            }
        }
    }
    return sum;
}

int main(void)
{
    int sum = 0;
    int *divisors = (int *)malloc( sizeof(int)*(LIMIT+1) );

    for (int i = 1; i <= LIMIT; i++) {
        divisors[i] = sumOfDivisors(i);
        if (divisors[i] < i) {
            if (divisors[divisors[i]] == i) {
                sum += i+divisors[i]; 
            }
        }
    }

    printf("%d\n", sum);
}
