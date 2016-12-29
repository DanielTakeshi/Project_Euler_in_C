/**
 * PE 016: Power Digit Sum. In Python you can just compute 2^(1000) directly but
 * here I decided to explicitly form the math and encode the digits one by one
 * into an array. When you print it using printArray you get the digits (albeit
 * in reverse order but doesn't really matter). It's fast:
 *
 * real   0m0.020s
 * user   0m0.003s
 * sys    0m0.002s
 */

#include <stdio.h>
const int LIMIT = 1000;

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) 
{
    int digits[300];
    digits[0] = 1;
    int totalDigits = 1;

    for (int i = 0; i < LIMIT; i++) {
        int carryOver = 0;
        for (int j = 0; j < totalDigits; j++) {
            int result = digits[j] * 2;
            digits[j] = (result % 10) + carryOver;
            carryOver = result / 10;
        }
        if (carryOver > 0) {
            digits[totalDigits] = carryOver;
            totalDigits++;
        }
        //printArray(digits, totalDigits);
    }

    int sum = 0;
    for (int i = 0; i < totalDigits; i++) {
        sum += digits[i];
    }
    printf("sum=%d\n",sum);
}
