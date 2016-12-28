/**
 * PE 017: Number letter counts. I'm not a huge fan of these kind of problems,
 * but they're easy. I want to speed up these so I can get to the harder ones.
 * Running time (while printing):
 *
 * real   0m0.020s
 * user   0m0.002s
 * sys    0m0.002s
 */

#include <stdio.h>
// ONE = 3;
// TWO = 3;
// THREE = 5;
// FOUR = 4;
// FIVE = 4;
// SIX = 3;
// SEVEN = 5;
// EIGHT = 5;
// NINE = 4;
// TEN = 3;
// ELEVEN = 6;
// TWELVE = 6;
// THIRTEEN = 8;
// FOURTEEN = 8;
// FIFTEEN = 7;
// SIXTEEN = 7;
// SEVENTEEN = 9;
// EIGHTEEN = 8;
// NINETEEN = 8;
// TWENTY = 6;
// THIRTY = 6;
// FORTY = 5;
// FIFTY = 5;
// SIXTY = 5;
// SEVENTY = 7;
// EIGHTY = 6;
// NINETY = 6;
// HUNDRED = 7;
// THOUSAND = 8;

int main(void) 
{
    int total = 0;
    int ones[] = {0,3,3,5,4,4,3,5,5,4}; // zero isn't included
    int tens[] = {3,6,6,8,8,7,7,9,8,8};
    int mult[] = {0,0,6,6,5,5,5,7,6,6};
    int hundred = 7;
    int thousand = 8;

    for (int i = 0; i < 10; i++) {
        total += ones[i];
        total += tens[i];
    }
    for (int num = 20; num < 100; num++) {
        int firstDigit = num / 10;
        int secondDigit = num % 10;
        total += mult[firstDigit] + ones[secondDigit];
    }
    for (int num = 101; num < 1000; num++) {
        int firstDigit = num / 100;
        int secondDigit = (num / 10) % 10;
        int thirdDigit = num % 10;
        if (secondDigit == 0) {
            printf("%d %d %d for %d\n", 
                ones[firstDigit],hundred,ones[thirdDigit], num);
            total += ones[firstDigit] + hundred + ones[thirdDigit];
        } else if (secondDigit == 1) {
            printf("%d %d %d for %d\n", 
                ones[firstDigit],hundred,tens[thirdDigit], num);
            total += ones[firstDigit] + hundred + tens[thirdDigit];
        } else {
            printf("%d %d %d %d for %d\n",
                ones[firstDigit],hundred,mult[secondDigit], ones[thirdDigit], num);
            total += ones[firstDigit] + hundred + mult[secondDigit] + ones[thirdDigit];
        }
        if (num % 100 != 0) {
            total += 3; // 'and'
        }
    }
    total += 3+hundred;
    total += 3+thousand;

    printf("%d\n", total);
}
