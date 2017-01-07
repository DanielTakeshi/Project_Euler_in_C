/**
 * PE 040: Chapernowne's Constant. I iterated through numbers and incremented
 * the number of cumulative digits. Then once it surpasses desired thresholds, I
 * extract the appropriate digit (took a few examples to figure out the
 * formula). As usual, the code is on the order of 0.1 seconds or less.
 *
 * real   0m0.032s
 * user   0m0.006s
 * sys    0m0.001s
 */

#include <stdio.h>
#include <math.h>

int getIndex(int number, int index) {
    int i = 0;
    int result = number % 10;
    while (i < index) {
        number /= 10;
        result = number % 10;
        i++;
    }
    return result;
}

int main(void)
{
    int product = 1;
    int totalDigits = 0;
    int t = 0;
    int desired[] = {1,10,100,1000,10000,100000,1000000};
    int desiredLength = 7;
    
    for (int i = 1; i <= 1000000; i++) {
        int numDigits = floor(log10(i))+1;
        totalDigits += numDigits;
        if (totalDigits >= desired[t]) {
            int digit = getIndex(i, totalDigits-desired[t]);
            printf("digit %d at index %d\n", digit, desired[t]);
            product *= digit;
            t++;
            if (t == desiredLength) break;
        }
    }

    printf("product: %d\n", product);
}
