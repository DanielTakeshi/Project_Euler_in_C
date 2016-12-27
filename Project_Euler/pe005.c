/**
 * PE 005: Smallest multiple. Times:
 *
 * real   0m0.182s
 * user   0m0.157s
 * sys    0m0.002s
 *
 * Another way to do this is by using prime factorizations.
 */

#include <math.h>
#include <stdio.h>


int satisfactory(int n, int limit) {
    for (int i = 2; i <= limit; i++) {
        if (n % i != 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int limit = 20;
    int i = limit;

    while(1) {
        if (satisfactory(i, limit)) {
            printf("%d\n",i);
            break;
        }
        i += limit;
    }
}
