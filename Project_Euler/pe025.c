/**
 * PE 025: 1000-Digit Fibonacci number. Like problem 20, I'm using gmp, Ubuntu,
 * and am compiling with:
 *
 *     gcc pe025.c -lgmp
 *
 * Here's a good source:
 *     https://www.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html
 *
 * Runtime is pretty fast, <1 second, though it's possible to do this w/pencil
 * and paper:
 * 
 * real   0m0.163s
 * user   0m0.160s
 * sys    0m0.000s
 */

#include <stdio.h>
#include <gmp.h>
const int NUM_DIGITS = 1000; // works for 3 and 1000

int numDigits(mpz_t n) {
    /* returns number of digits of mpz_t object */
    int numDigits = 0;
    while (mpz_sgn(n) > 0) {
        mpz_div_ui(n, n, 10); // n = n/10
        numDigits++;
    }
    return numDigits;
}

int main ()
{
    mpz_t f1;
    mpz_t f2;
    mpz_t curr;

    mpz_init(f1);
    mpz_init(f2);
    mpz_init(curr);

    mpz_set_ui(f1, 1);
    mpz_set_ui(f2, 1);
    mpz_set_ui(curr, 2);

    int index = 2;
    while (numDigits(curr) < NUM_DIGITS) {
        mpz_add(curr, f1, f2); // curr = f1 + f2
        //mpz_out_str(stdout, 10, curr);
        //printf("\n");
        index++;
        mpz_set(f1, f2); // f1 = f2
        mpz_set(f2, curr); // f2 = curr
    }
    printf("answer: %d\n", index);

    mpz_clear(f1); 
    mpz_clear(f2); 
    mpz_clear(curr); 
}
