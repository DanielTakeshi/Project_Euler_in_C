/**
 * PE 012: Highly divisible triangular number. Brute force. It's quite slow:
 *
 * real   0m0.606s
 * user   0m0.587s
 * sys    0m0.002s
 *
 * There's a better solution using prime factorizations: determine prime
 * factorization, then multiply all the exponents together (the exponents have
 * to be incremented by one).
 */

#include <math.h>
#include <stdio.h>

int const THRESHOLD = 500;


int getNumFactors(int n) {
    /* We already count 1 and n */
    int num = 2;
    for (int i = 2; i < n/sqrt(n); i++) {
        if (n % i == 0) {
            num += 2;
        }
    }
    int root = sqrt(n);
    if (root * root == n) {
        num++;
    }
    return num;
}


int main(void) 
{
    int limit = 20000;
    int triNumber = 1; // Let's just start with 1
    for (int i = 2; i <= limit; i++) {
        triNumber += i;
        int numFactors = getNumFactors(triNumber);
        if (numFactors > THRESHOLD) {
            printf("triangular number index: %d\n", i);
            printf("triangular number: %d\nnumber of factors: %d\n",
                triNumber, numFactors);
            break;
        }
    }
}
