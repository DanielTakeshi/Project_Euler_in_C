/**
 * PE 035: Circular Primes. it runs in about 0.1 seconds. I made a sieve and
 * then I counted via rotations.
 *
 * real   0m0.095s
 * user   0m0.075s
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
    int total = 0;
    for (int i = 2; i < LIMIT; i++) {
        if (sieve[i] == 1) {
            // Got this from StackOverflow. :-) The number of digits MINUS 1.
            int numRotations = floor(log10(i));
            int yes = 1;
            int newNum = i;
            for (int j = 0; j < numRotations; j++) {
                // This does the 'rotation'.
                newNum = ((int) (newNum%10)*pow(10,numRotations)) + (newNum/10);
                if (sieve[newNum] != 1) yes = 0;
            }
            if (yes) total++;
        }
    }

    printf("total: %d\n", total);
    free(sieve);
}
