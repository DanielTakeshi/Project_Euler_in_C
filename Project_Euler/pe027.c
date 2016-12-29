/**
 * PE 027: Quadratic Primes. Yeah, this was mostly brute-force. Look at the
 * thread, there's a LOT of good stuff which might be useful for a future
 * problem.
 *
 * real   0m0.125s
 * user   0m0.106s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <math.h>


int isPrime(int n) {
    int factors = 2;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factors++;
            break;
        }
    }
    return (factors==2 && n>1) ? 1 : 0;
}


int main(void) 
{
    int maxConsecutive = 40;   // I.e. n = 0, ... , 39
    int finalA = 1001;
    int finalB = 1001;

    int consecutive;
    int n;

    for (int a = -999; a < 1000; a++) {
        // There are better ways to incremement b (since it should always be
        // prime) but this will do for this problem.
        for (int b = 3; b <= 1000; b+=2) {
            consecutive = 0;
            n = 0;
            while (isPrime(n*n + a*n + b)) {
                consecutive++;
                n++;
            }
            if (consecutive > maxConsecutive) {
                maxConsecutive = consecutive;
                finalA = a;
                finalB = b;
            }
        }
    }
    printf("a=%d, b=%d, a*b=%d\n", finalA,finalB,finalA*finalB);
}
