/**
 * PE 029: Distinct Powers. Again, I am using gmp so I need to compile on my
 * Ubuntu machine with `gcc pe029.c -lgmp`. PS: I learned a new function,
 * gmp_printf(...); Much better than what I was doing earlier ... man, gmp.h
 * seems like a great library. It's slower than using BigInteger in Java and
 * certainly slower than doing everything explicitly in Python. At least the
 * _execution_ time is still fast, less than a second as usual:
 *
 * real   0m0.112s
 * user   0m0.108s
 * sys    0m0.000s
 */


#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(void) 
{
    int total = 0;
    int low = 2;
    int high = 100;

    mpz_t n;
    mpz_t base;
    mpz_init(n);
    mpz_init(base);

    mpz_t *distinctValues;
    distinctValues = malloc(sizeof(mpz_t) * 9801);

    for (int a = low; a <= high; a++) {
        mpz_set_ui(base, a);
        for (int b = low; b <= high; b++) {
            mpz_pow_ui(n, base, b);
            //gmp_printf("%Zd\n", n);

            int new = 1;
            for (int t = 0; t < total; t++) {
                if (mpz_cmp(n, distinctValues[t]) == 0) {
                    // gmp_printf("equal: %Zd and %Zd\n", base, distinctValues[t]);
                    new = 0;
                    break;
                }
            }
            if (new) {
                mpz_set(distinctValues[total], n);
                
                total++;
            }
        }
    }

    printf("total: %d\n", total);
    mpz_clear(n);
    mpz_clear(base);
}
