/**
 * PE 030: Digit Fifth Powers. Looks like most people did brute force like I did
 * (though I tested only 3-6 digit numbers, not 1-2 digits). Another way is to
 * just look at all the combinations of digits since we know what their sum of
 * exponentials will be. Anyway, the code is pretty fast if a but ugly.
 *
 * real   0m0.022s
 * user   0m0.005s
 * sys    0m0.002s
 */

#include <stdio.h>

int main(void) 
{
    int pows[] = {0, 1, 32, 243, 1024, 3125, 77776, 16807, 32768, 59049};
    int cumsum = 0;

    for (int i = 100; i <= 999; i++) {
        int val = i;
        int sum = pows[i/100] + pows[(i/10)%10] + pows[i%10];
        if (val == sum) {
            printf("val=%d, sum_of_5th_powers=%d\n", val, sum);
            cumsum += val;
        }

        for (int j = 0; j <= 9; j++) {
            int val2 = val*10 + j;
            int sum2 = sum + pows[j];
            if (val2 == sum2) {
                printf("val=%d, sum_of_5th_powers=%d\n", val2, sum2);
                cumsum += val2;
            }

            for (int k = 0; k <= 9; k++) {
                int val3 = val2*10 + k;
                int sum3 = sum2 + pows[k];
                if (val3 == sum3) {
                    printf("val=%d, sum_of_5th_powers=%d\n", val3, sum3);
                    cumsum += val3;
                }

                for (int l = 0; l <= 9; l++) {
                    int val4 = val3*10 + l;
                    int sum4 = sum3 + pows[l];
                    if (val4 == sum4) {
                        printf("val=%d, sum_of_5th_powers=%d\n", val4, sum4);
                        cumsum += val4;
                    }
                }
            }
        }
    }
    
    printf("cumsum=%d\n", cumsum);
}
