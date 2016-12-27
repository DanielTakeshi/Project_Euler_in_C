/**
 * Brute force solution, but works.
 * Oh and next time combine these two loops into one ...
 */

#include <stdio.h>

int main()
{
    int sum_squares = 0;
    for (int i = 0; i <= 100; i++) {
        sum_squares += i*i;
    }
    int square_of_sum = 0;
    for (int i = 0; i <= 100; i++) {
        square_of_sum += i;
    }
    square_of_sum = square_of_sum * square_of_sum;
    printf("s-o-s=(%d) - s-sq=(%d) = (%d)\n", square_of_sum, sum_squares,
        square_of_sum-sum_squares);
}
