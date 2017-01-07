/**
 * PE 049: Prime Permutations. Given that we *know* we're only dealing with
 * 4-digit numbers, a sieve is not necessary for fast performance. Another
 * takeaway from this code is how to do permutations. If we assume they're both
 * 4-digit numbers, make a char array of size PLUS ONE (I think the last
 * character is an annoying \0 term), then we can sprintf, get the 'string'
 * formatted there, THEN sort using qsort, THEN use strcmp. That seems faster
 * and more elegant than trying to keep track of digits manually. The downside
 * is that qsort requires a cmpfunc function but those are usually simple
 * copy/paste jobs from online.
 *
 * real   0m0.084s
 * user   0m0.065s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    /* the usual comparison function for quicksort */
    return *(const char *)a - *(const char *)b;
}

int isPermutation(int i, int j) {
    /* assumes i,j are 4-digit numbers; copies into _string_ then sort */
    char num1[4+1];
    char num2[4+1];
    sprintf(num1, "%d",i);
    sprintf(num2, "%d",j);
    qsort(num1, 4, sizeof(char), cmpfunc);
    qsort(num2, 4, sizeof(char), cmpfunc);
    return !strcmp(num1,num2);
}

int isPrime(int n) {
    /* primality test, assumes n >= 2 */
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int num1, num2, num3;
    num1 = num2 = num3 = 1001;
    int done = 0;
    
    while (!done) {
        num1 += 2;
        // 'gap' is here because we need an arithmetic sequence
        if (isPrime(num1) && num1 != 1487) {
            for (int gap = 2; gap < 5000; gap++) {
                num2 = num1 + gap;
                num3 = num2 + gap;
                if (num3 < 10000 && isPrime(num2) && isPrime(num3) \
                    && isPermutation(num1,num2) && isPermutation(num2,num3)) {
                    done = 1;
                    break;
                }
            }
        }
    }

    printf("num1 num2 num3 are:\n%d %d %d\n", num1, num2, num3);
}
