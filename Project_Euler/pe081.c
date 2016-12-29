/**
 * PE 081: Path sum, two ways. Another straightforward dynamic programming
 * problem. It's pretty fast:
 *
 * real   0m0.020s
 * user   0m0.002s
 * sys    0m0.002s
 */

#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void loadMatrix(int matrix[][80]) {
    // To parse with commas, use '%d,'. Surprisingly, it works even without me
    // taking into account newlines. I definitely need to know fscanf.
    FILE *f = fopen("files/pe081.txt", "r");
    for (int x = 0; x < 80; x++) {
        for (int y = 0; y < 80; y++) {
            fscanf(f, "%d,", &matrix[x][y]);
        }
    }
    fclose(f);
}

int main(void) 
{
    int matrix[80][80];
    loadMatrix(matrix);
    
    for (int i = 1; i < 80; i++) {
        matrix[0][i] += matrix[0][i-1];
        matrix[i][0] += matrix[i-1][0];
    }

    for (int x = 1; x < 80; x++) {
        for (int y = 1; y < 80; y++) {
            matrix[x][y] += MIN(matrix[x-1][y], matrix[x][y-1]);
        }
    }

    printf("max path sum: %d\n", matrix[79][79]);
}
