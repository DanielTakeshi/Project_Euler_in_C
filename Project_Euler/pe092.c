/**
 * PE 092: Square digit chains. Yet another dynamic programming problem. Yeah, I
 * like those. My code is actually somewhat slow, almost a second long! There
 * are better ways to do this (see discussion forums).
 *
 * real   0m0.921s
 * user   0m0.879s
 * sys    0m0.018s
 */

#include <stdio.h>
#include <stdlib.h>
const int LIMIT = 10000000;

int addSquareDigits(int n) {
    int sum = 0;
    int digit;
    while (n > 0) {
        digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main(void) 
{
    // 0 means doesn't go to 89, 1 means goes to 89
    int *results = (int *)malloc(sizeof(int)*LIMIT); 
    results[0] = 0;
    results[1] = 0;
    results[89] = 1;

    int val;
    for (int i = 2; i < LIMIT; i++) {
        val = i;
        while (val >= i && val != 89) {
            val = addSquareDigits(val);
        }
        //printf("i=%d, val=%d\n",i,val);
        if (val == 89 || results[val] == 1) {
            results[i] = 1;
        } else {
            results[i] = 0;
        }
    }
    
    int total = 0;
    for (int i = 0; i < LIMIT; i++) {
        total += results[i];
    }
    printf("%d\n", total);
}
