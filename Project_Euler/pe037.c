/**
 * PE 037: Truncable Primes. I adapted this code from Problem 35 by using a
 * sieve at the start. The limit has to be hand-tuned, though, but we can just
 * incrementally increase it until we get to all 11 numbers.
 *
 * And of course, the last truncable prime (the eleventh one) had to be a large
 * one ... wow that was a nice surprise. :) PS: of course, use if(sieve[i])
 * instead of if(sieve[i] == 1) like I used to. Lesson learned!
 *
 * real   0m0.104s
 * user   0m0.084s
 * sys    0m0.003s
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
const int LIMIT = 1000000;

int main(void)
{
    // The sieve. 1=Prime, 0=Not prime. Don't count first i multiple.
    int *sieve = (int *)malloc(sizeof(int)*LIMIT);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i < LIMIT; i++) {
        sieve[i] = 1;
    }
    for (int i = 2; i <= sqrt(LIMIT); i++) {
        for (int j = i*2; j < LIMIT; j+=i) {
            sieve[j] = 0;
        }
    }

    // Now we can iterate through the prime numbers.
    int sum = 0;
    for (int i = 10; i < LIMIT; i++) {
        if (sieve[i]) {
            int copy1 = i;
            int copy2 = i;
            int yes = 1;
            while (copy1 > 10) {
                copy1 /= 10;
                if (!sieve[copy1]) yes = 0;
            }
            while (copy2 > 10) { // Note: floor(log10(copy2)) is #digits-1.
                copy2 = copy2 % ( (int) pow(10, floor(log10(copy2))) );
                if (!sieve[copy2]) yes = 0;
            }
            if (yes) {
                printf("%d\n",i);
                sum += i;
            }
        }
    }

    printf("sum: %d\n", sum);
    free(sieve);
}
