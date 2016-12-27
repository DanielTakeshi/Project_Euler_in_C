/**
 * PE 009: Special Pythagorean Triplet. Brute force solution, sorry! But
 * heck, I did this one really fast. Times:
 *
 * real   0m0.394s
 * user   0m0.367s
 * sys    0m0.004s
 */

#include <stdio.h>

int main(void) 
{
    for (int a = 1; a < 1000; a++) {
        for (int b = a+1; b < 1000; b++) {
            for (int c = b+1; c < 1000; c++) {
                if (a+b+c == 1000) {
                    if (a*a+b*b == c*c) {
                        printf("a=%d, b=%d, c=%d\n", a,b,c);
                        printf("a^2=%d, b^2=%d, c^2=%d\n", a*a,b*b,c*c);
                        printf("a*b*c = %d\n", a*b*c);
                        break;
                    }
                }
            }
        }
    }
}
