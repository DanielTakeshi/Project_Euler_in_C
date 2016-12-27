/**
 * PE 004: largest palindrome, solved w/time:
 *
 * real   0m0.064s
 * user   0m0.046s
 * sys    0m0.002s
 *
 * Seems like most people did something similar.
 */

#include <stdio.h>

int isPalindrome(int n) {
    // Assumes number of digits is at least 2
    // For this particular problem we won't see more than 6 digits.
    int numDigits;
    if (n < 1000000) numDigits = 6;
    if (n < 100000) numDigits = 5;
    if (n < 10000) numDigits = 4;
    if (n < 1000) numDigits = 3;
    
    // strAsChar contains array representation, e.g. 100 ==> [1,0,0].
    char strAsChar[numDigits];
    sprintf(strAsChar, "%d\n", n); // neat!
    for (int i = 0; i < numDigits/2; i++) {
        if (strAsChar[i] != strAsChar[numDigits-i-1]) {
            return 0;
        }
    }
    //printf("%d\n",n);
    return 1;
}

int main(void)
{
    int largest = -1;

    // Only one real optimization, starting from y=x to avoid repetition.
    for (int x = 100; x < 1000; x++) {
        for (int y = x; y < 1000; y++) {
            int candidate = x*y;
            if (isPalindrome(candidate) && candidate>largest) {
                largest = candidate;
            }
        }
    }
    printf("largest palindrome: %d\n",largest);
}
