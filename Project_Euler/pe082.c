/**
 * PE 082: Path sum, three ways. This was similar to dynamic programming.
 * I proceeded from left to right, and for each column updating the matrix as we
 * go by. To do this, you have to scan each column up and down (starting from
 * current component) and then adding certain elements in the previous column).
 * It's pretty fast:
 *
 * real   0m0.022s
 * user   0m0.004s
 * sys    0m0.002s
 */

#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

void loadMatrix(int matrix[][80]) {
    // To parse with commas, use '%d,'. Surprisingly, it works even without me
    // taking into account newlines. I definitely need to know fscanf.
    FILE *f = fopen("files/pe082.txt", "r");
    for (int x = 0; x < 80; x++) {
        for (int y = 0; y < 80; y++) {
            fscanf(f, "%d,", &matrix[x][y]);
        }
    }
    fclose(f);
}

int main(void) 
{
    int easy[80][80];
    loadMatrix(easy);

    for (int col = 1; col < 80; col++) {
        int newCol[80];

        for (int row = 0; row < 80; row++) {
            int mini = easy[row][col] + easy[row][col-1];

            int cumsum = easy[row][col];
            for (int r = row+1; r < 80; r++) {
                cumsum += easy[r][col];
                int val = cumsum + easy[r][col-1];
                if (val < mini) {
                    mini = val;
                }
            }

            cumsum = easy[row][col];
            for (int r = row-1; r >= 0; r--) {
                cumsum += easy[r][col];
                int val = cumsum + easy[r][col-1];
                if (val < mini) {
                    mini = val;
                }
            }

            newCol[row] = mini;
        }

        for (int row = 0; row < 80; row++) {
            easy[row][col] = newCol[row];
        }
    }

    int result = 10000000;
    for (int i = 0; i < 80; i++) {
        if (easy[i][79] < result) {
            result = easy[i][79];
        }
    }
    printf("result=%d\n", result);
}
