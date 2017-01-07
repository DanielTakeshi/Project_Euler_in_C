/**
 * PE 046: Goldbach's Other Conjecture. Brute force, pretty fast. If the answer
 * had been larger I'd probably need a sieve, among other things.
 *
 * real   0m0.043s
 * user   0m0.025s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    /* primality test, assumes n >= 2 */
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int result = 33;
    int notDone;
    do {
        result += 2;
        notDone = 0;
        if (!isPrime(result)) {
            // now check if it cannot be written as prime + 2*square
            for (int i = 3; i <= result-2; i++) {
                double otherTerm = (result-i) / 2;
                if (isPrime(i) && (sqrt(otherTerm) == otherTerm/((int)sqrt(otherTerm)))) {
                    notDone = 1;
                    break;
                }
            }
        } else {
            notDone = 1;
        }
    } while (notDone);
    printf("result: %d\n", result);
}
