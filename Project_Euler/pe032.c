/**
 * PE 032: Pandigital Products. Note that for x*y=z to satisfy the pandigital
 * requirement, we must have (x,y) represent a 1-digit and a 4-digit number WLOG
 * or (as in the problem example) a 2-digit and a 3-digit number WLOG. Also,
 * note that our bounds for x and y should never include a 0 and should have
 * different digits.
 *
 * By the way, the sum over-counts some duplicates but there are only a few and
 * the code prints them out. There are two numbers which appear twice, hence
 * it's easy to subtract the numbers from the 'sum' to get the final result. If
 * I was really picky, I'd put all encountered numbers in an array and then,
 * each time I needed to add a number, I'd scan the array and check if the
 * number is there.
 *
 * real   0m0.025s
 * user   0m0.007s
 * sys    0m0.002s
 */

#include <stdio.h>

int isPandigital(int x, int y, int z) {
    /** returns 1 if x,y,z concatenated w/each other are pandigital, 0 o.w.  */
    int digits[] = {1,0,0,0,0,0,0,0,0,0}; // 1 means its encountered
    int digitsX = 0;
    int digitsY = 0;
    int digitsZ = 0;

    while (x > 0) {
        digits[x % 10] = 1;
        x /= 10;
        digitsX++;
    }
    while (y > 0) {
        digits[y % 10] = 1;
        y /= 10;
        digitsY++;
    }
    while (z > 0) {
        digits[z % 10] = 1;
        z /= 10;
        digitsZ++;
    }
    for (int i = 0; i < 10; i++) {
        if (digits[i] == 0) return 0;
    }
    if (digitsX + digitsY + digitsZ != 9) return 0;
    return 1;
}

int main(void)
{
    int sum = 0;
    int prod;

    for (int x = 2; x <= 98; x++) {
        for (int y = 123; y <= 9876; y++) {
            prod = x*y;
            if (1000 <= prod && prod < 10000) {
                if (isPandigital(x,y,prod)) {
                    printf("x*y=z is %d*%d=%d\n", x,y,prod);
                    sum += prod;
                }
            }
        }
    }

    printf("sum: %d\n", sum);
}
