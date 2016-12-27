/**
 * PE 014: Longest Collatz Sequence. Short and straightforward dynamic
 * programming solution. It's pretty fast:
 * 
 * real   0m0.132s
 * user   0m0.104s
 * sys    0m0.005s
 */

#include <stdio.h>

const int LIMIT = 1000000;

int main(void) 
{
    int collatzLengths[LIMIT];
    collatzLengths[0] = 0;
    collatzLengths[1] = 1;
    long long num;
    int count;
    int longestChainLength = 1;
    int longestChainStart = 1;

    for (int i = 2; i < LIMIT; i++) {
        num = i;
        count = 0;
        while (num >= i) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = 3*num+1;
            }
            count++;
        }
        collatzLengths[i] = count + collatzLengths[num];
        if (collatzLengths[i] > longestChainLength) {
            longestChainLength = collatzLengths[i];
            longestChainStart = i;
        }
    }
    printf("starting number for longest chain: %d\n", longestChainStart);
    printf("that number has chain length: %d\n", longestChainLength);
}
