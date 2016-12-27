/**
 * PE 003: Largest prime factor. The solution is correct as it is, with the
 * following times:
 * 
 *  real   0m0.004s
 *  user   0m0.001s
 *  sys    0m0.002s
 * 
 * Though I think if the numbers get much larger, it would be better to use a
 * sieve instead of iterating through the factors. This code uses the fact that
 * every number has a unique prime factorization.
 */

#include <math.h>
#include <stdio.h>


int isPrime(int n) {
    /* Standard C convention, returns 0 if false, 1 if true. */
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n/sqrt(n)+1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    // This is too large for ints, which on my system are 32 bits.
    // I could actually use longs since they're 64 bits (again, on my system),
    // but long long seems to be the safer way to go.

    long long num_ll = 600851475143;
    //long long num_ll = 13195; // Test case
    printf("Number as input: %llu\n", num_ll);

    int factor = 2;
    while (num_ll != 1) {
        while (num_ll % factor == 0) {
            printf("dividing by prime factor %d\n", factor);
            num_ll = num_ll / factor;
        }
        factor = factor + 1;
        while (!isPrime(factor)) {
            factor = factor + 1;
        }
    }
}
