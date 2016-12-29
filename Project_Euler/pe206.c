/**
 * PE 206: Concealed square. Pretty bad code, the only optimization is to
 * increment by 1000 instead of 10.
 *
 * real   0m12.589s
 * user   0m12.564s
 * sys    0m0.007s
 */

#include <stdio.h>
#include <math.h>

long long getNumFromDigits(int digits[]) {
    long long result = 0;
    long long factor = 1;
    for (int i = 0; i < 19; i++) {
        result += digits[18-i] * factor;
        factor *= 10;
    }
    return result;
}

void insertIntoDigits(int digits[], int extraDigits) {
    for (int i = 15; i >= 1; i-=2) {
        digits[i] = extraDigits % 10;
        extraDigits /= 10;
    }
}

int main(void) 
{
    int digits[] = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,0};
    printf("starting number:%llu\n", getNumFromDigits(digits));
    printf("with square root:%f\n", sqrt(getNumFromDigits(digits)));
    printf("with casted square root:%llu\n", (long long)sqrt(getNumFromDigits(digits)));

    int extraDigits = 0;
    while (extraDigits < 99999999) {
        insertIntoDigits(digits, extraDigits);
        long long candidate = getNumFromDigits(digits);
        long long root = (long long)sqrt(candidate);
        if (root * root == candidate) {
            printf("candidate: %llu\n", candidate);
            printf("root: %llu\n", root);
            break;
        }
        extraDigits++;
    }
}
