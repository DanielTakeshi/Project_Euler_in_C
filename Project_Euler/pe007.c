/**
 * PE 007: 10001st prime number. Wow, this works and was faster than I thought:
 * 
 * real   0m0.004s
 * user   0m0.001s
 * sys    0m0.002s
 *
 * Though again, I better start using sieves soon ... maybe some of the harder
 * problems will require that.
 */

#include <math.h>
#include <stdio.h>


int isPrime(int n) {
    /* Standard C convention, returns 0 if false, 1 if true. */
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
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
    int numPrimes = 0;
    int limit = 10001;
    int i = 2;
    int mostRecent = -1;

    while (numPrimes < limit) {
        if (isPrime(i)) {
            numPrimes++;
            mostRecent = i;
        }
        i++;
    }
    printf("prime #%d is %d\n", limit,mostRecent);
}
