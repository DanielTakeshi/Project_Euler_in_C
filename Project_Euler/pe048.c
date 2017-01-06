/**
 * PE 048: Modular Exponentiation. I had forgotten how modular arithmetic works.
 * I decided to iterate through all the 1000 terms, and for each compute the
 * last 10 digits of b^b, then add them up. It's OK to only compute the last 10
 * digits for each term since we can sum those up and that is all we care about
 * (we have to do an additional mod once we sum it up since it will be just over
 * 10 digits of course). Lots of memories of abstract algebra! The code is fast:
 *
 * real   0m0.028s
 * user   0m0.011s
 * sys    0m0.002s
 */

#include <stdio.h>
const int LIMIT = 1000;

int main(void)
{
    long long lastTens = 0;
    long long modulo = 10000000000LL;

    for (int b = 1; b <= LIMIT; b++) {
        // Now compute (b^b mod modulo) and add to lastTens
        // Computed via modular exponentation strategies
        // See: https://en.wikipedia.org/wiki/Modular_exponentiation
        long long c = 1LL;
        for (int i = 1; i <= b; i++) {
            c = (c * b) % modulo;
        }
        lastTens += c;
    }
    printf("result:%llu\n", lastTens % modulo);
}
