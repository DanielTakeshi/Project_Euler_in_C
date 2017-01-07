/**
 * PE 047: Consecutive Primes. Note that one number in our sequence of four must
 * be at least 5 x 7 x 11 x 13 = 5005, hence the lower bound for num starts at
 * 5002. Also, I did this problem earlier, but I used a _set_ to store
 * the factors. But that's not needed here!! When we iterate from i=1 to
 * sqrt(n), that will take care of the uniqueness for us!! This means my code
 * remains fast, it's about 0.3 seconds, I suppose it could be faster but
 * anything less than a second is usually OK with me.
 *
 * real   0m0.342s
 * user   0m0.315s
 * sys    0m0.004s
 *
 * I solved it and got the following message from Project Euler:
 *
 * Nice work, DanielSeita, you've just advanced to Level 2. 
 * 39720 members (5.96%) have made it this far.
 *
 */

#include <stdio.h>
#include <math.h>
int const NUMBER = 4; // works for 3 w/different starting value
int const START = 5002;

int isPrime(int n) {
    /* primality test, assumes n >= 2 */
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int result = -1;
    int consecutive = 0;
    int num = START;

    while (consecutive < NUMBER) {
        int nPrimes = 0;
        for (int i = 2; i*i <= num; i++) {
            if (num % i == 0 && isPrime(i)) {
                nPrimes++;
            }
            if (num % (num/i) == 0 && isPrime(num/i) && i != (int)sqrt(num)) {
                nPrimes++;
            }
        }
        if (nPrimes >= NUMBER) {
            consecutive++;
            result = num-(NUMBER-1); // subtract!!
        } else {
            consecutive = 0;
        }
        num++;
    }

    printf("result: %d\n", result);
}
