/**
 * Update: problem has been solved successfully. Lol.
 */

#include <stdio.h>

int main()
{
    int t1 = 1;
    int t2 = 2;
    int cur_num = t1 + t2;
    int sum = 2;

    while (cur_num < 4000000) 
    {
        if (cur_num % 2 == 0) {
            sum += cur_num;
        }
        t1 = t2;
        t2 = cur_num;
        cur_num = t1 + t2;
    }
    printf("sum = %d\n", sum);
}
