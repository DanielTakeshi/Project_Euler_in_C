/**
 * PE 041: Pandigital Primes. Since it's asking for the largest one, I started
 * with a 7-digit number and then worked my way down. Using all 1-9 means the
 * sum is 45, hence the number is divisible by 3 and not prime. For 1-8 we get
 * the sum of 36 so it's divisible by 3. Note the obvious reason why the `i`
 * index decrements by 2, to maintain the possibility of it being prime.
 *
 * Note: I did this one in a bit of a rush. I haven't rigorously verified the
 * isPandigital function.
 *
 * Also, I think there might be a faster way to do this using bit manipulation.
 * I will check the CS 61C lectures at Berkeley for more about this kind of
 * operation.
 * 
 * real   0m0.018s
 * user   0m0.001s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    /* Standard C convention, returns 0 if false, 1 if true. */
    for (int i = 2; i <= n/sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int isPandigital(int n) {
    /* Standard C convention, returns 0 if false, 1 if true. */
    int digits[8];
    int i = 0;

    while (n > 0) {
        digits[i] = n % 10;
        n /= 10;
        i++;
        // Check for duplicates
        for (int j = 0; j < i; j++) {
            if (digits[j] == digits[i]) return 0;
        }
    }

    // check for 1 to, in python speak, len(n).
    for (int j = 0; j < i; j++) {
        if (digits[j] > i) return 0;
    }
    return 1;
}

int main(void)
{
    for (int i = 7654321; i >= 2143; i -= 2) {
        if (isPandigital(i) && isPrime(i)) {
            printf("solution:%d\n",i);
            break;
        }
    }
}
