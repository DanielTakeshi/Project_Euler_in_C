/**
 * PE 028: Number spiral diagonals. The solution is to determine a patten for
 * the corner terms, test on smaller cases, then try on 1001. It was fast:
 * 
 * real   0m0.019s
 * user   0m0.001s
 * sys    0m0.002s
 */

#include <stdio.h>
const int DIMENSION = 1001;

int main(void) 
{
    int sum = 1;    // Running sum
    int val = 1;    // Each loop, indicates value of max corner term
    int factor = 0; // Length of diagonals

    while (val < DIMENSION*DIMENSION) {
        factor += 2;
        for (int i = 1; i <= 4; i++) {
            sum += val + (i * factor);
        }
        val = (factor+1)*(factor+1);
    }

    printf("sum=%d\n", sum);
}
