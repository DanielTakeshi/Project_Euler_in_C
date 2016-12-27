/**
 * PE 010: Summation of Primes. Now I finally use a sieve.
 *
 * real   0m0.162s
 * user   0m0.133s
 * sys    0m0.006s
 *
 * Got confused for a sec, but turns out it was a simple int overflow.
 */

#include <stdio.h>
#include <math.h>

const int limit = 2000000; // test with 10 and 2,000,000

int main(void) 
{
    // The sieve. 1=Prime, 0=Not prime.  We deal w/indices, so start with
    // sieve[2], i.e. third element, as the first prime. Ignore first two.
    int sieve[limit+1]; 
    sieve[0] = 0;
    sieve[1] = 0;

    for (int i = 0; i <= limit; i++) {
        sieve[i] = 1;
    }

    // Form the sieve. The 'j' needs to start at the next multiple of i.
    for (int i = 2; i <= sqrt(limit)+1; i++) {
        for (int j = i*2; j <= limit; j+=i) {
            sieve[j] = 0;
        }
    }

    // Sum up the primes.
    long long sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i] == 1) {
            sum += i;
            //printf("prime=%d, sum=%llu\n", i, sum);
        }
    }
    printf("sum of primes: %llu", sum);
}
