/**
 * PE 099: Largest Exponential. Any machine learning person should be able to do
 * this since we take logarithms all the time! Definitely very easy for me.
 *
 * real   0m0.017s
 * user   0m0.002s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <math.h>

void loadMatrix(int matrix[1000][2]) {
    FILE *f = fopen("files/pe099.txt", "r");
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 2; y++) {
            fscanf(f, "%d,", &matrix[x][y]);
        }
    }
    fclose(f);
}

int main(void) 
{
    int matrix[1000][2];
    loadMatrix(matrix);
    int bestLine = -1;
    double bestVal = -1;
    double currVal;

    for (int i = 0; i < 1000; i++) {
        currVal = matrix[i][1] * log(matrix[i][0]);
        if (currVal > bestVal) {
            bestLine = i;
            bestVal = currVal;
        }
    }

    printf("%d\n", bestLine+1); // Use +1
}
