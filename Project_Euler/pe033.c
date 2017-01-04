/**
 * PE 033: Digit Cancelling Fractions. Note: I got the unsimplified fraction,
 * then I got the simplified one by just reducing it myself. Sorry. Anyway it
 * wasn't that bad.
 *
 * real   0m0.023s
 * user   0m0.001s
 * sys    0m0.002s
 */

#include <stdio.h>

int main(void) 
{
    int numProd = 1;
    int denProd = 1;

    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            double numerator = 10.0*i + j;
            for (int k = i; k <= 9; k++) {
                double denominator = 10.0*j + k;
                double ratio = numerator / denominator;
                if (ratio == ((double)i)/k && numerator != denominator) {
                    printf("num/den = %d/%d\n",
                           (int)numerator,(int)denominator);
                    numProd *= (int)numerator;
                    denProd *= (int)denominator;
                }
            }
        }
    }

    printf("answer (unsimplified): %d/%d\n", numProd, denProd);
}
