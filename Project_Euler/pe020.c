/**
 * PE 020: Factorial Digit Sum. I learned something new here, how to use the
 * gmp library! =) Thank goodness for these examples online!  On my Ubuntu 16.04
 * machine, I compiled with this command:
 *
 *     gcc pe020.c -lgmp
 *
 * I am still not completely sure how compilation works. I couldn't get this
 * working on my Mac since it was getting that dreaded symbol not found error
 * from clang. And I don't have gcc working on my Mac. Ugh. But on my Ubuntu
 * machine, it's blazingly fast:
 * 
 * real   0m0.001s
 * user   0m0.000s
 * sys    0m0.004s
 */

#include <stdio.h>
#include <gmp.h>
// #include <openssl/bn.h>

int main ()
{
    int limit = 100;
    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, 1);

    for (int i = 1; i <= limit; i++) {
        mpz_mul_ui(n, n, i); // n = n*i
    }

    mpz_t r;
    mpz_init(r);
    mpz_t d;
    mpz_init(d);
    mpz_set_ui(d,10);

    int sum = 0;
    while (mpz_sgn(n) > 0) {
        mpz_mod(r, n, d); // get last digit
        mpz_div_ui(n, n, 10); // n = n/10
        sum += mpz_get_si(r);
    }
    printf("%d\n", sum);

    mpz_clear(n); 
    mpz_clear(r); 
    mpz_clear(d); 
}
