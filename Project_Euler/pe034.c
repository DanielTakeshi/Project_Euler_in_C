/**
 * PE 034: Digit Factorials. Pretty straightforward brute force, the upper bound
 * could be reduced a bit I think. But it's still <1 second.
 *
 * real   0m0.673s
 * user   0m0.654s
 * sys    0m0.002s
 */

#include <stdio.h>

int main(void) 
{
    int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    for (int i = 10; i < 10000000; i++) {
        int val = i;
        int sum = 0;
        while (val > 0) {
            sum += facts[val % 10];
            val /= 10;
        }
        if (sum == i) {
            printf("val=%d, sum=%d\n", val, sum);
        }
    }
}
