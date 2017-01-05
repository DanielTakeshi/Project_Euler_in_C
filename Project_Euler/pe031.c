/**
 * PE 031: Coin Sums. Ugly but it works. It's "smart brute force" but I guess
 * another way is to start with 200 and just count down?
 *
 * real   0m0.027s
 * user   0m0.010s
 * sys    0m0.002s
 */


#include <stdio.h>

int main(void) 
{
    int result = 0;
    for (int twoH = 0; twoH <= 200; twoH += 200) {
        for (int oneH = twoH; oneH <= 200; oneH += 100) {
            for (int fifty = oneH; fifty <= 200; fifty += 50) {
                for (int twenty = fifty; twenty <= 200; twenty += 20){
                    for (int ten = twenty; ten <= 200; ten += 10){
                        for (int five = ten; five <= 200; five += 5) {
                            for (int two = five; two <= 200; two += 2) {
                                for (int one = two; one <= 200; one++) {
                                    if (one == 200) {
                                        result++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("result:%d\n", result);
}
