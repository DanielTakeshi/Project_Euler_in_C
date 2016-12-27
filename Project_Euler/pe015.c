/**
 * PE 015: Lattice Paths. Another dynamic programming one.
 *
 * real   0m0.018s
 * user   0m0.001s
 * sys    0m0.002s
 */

#include <stdio.h>
const int LENGTH = 20+1; // Need extra +1

int main(void) 
{
    long long grid[LENGTH][LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        grid[i][0] = 1;
        grid[0][i] = 1;
    }
    for (int x = 1; x < LENGTH; x++) {
        for (int y = 1; y < LENGTH; y++) {
            grid[x][y] = grid[x][y-1] + grid[x-1][y];
        }
    }
    printf("%llu\n", grid[LENGTH-1][LENGTH-1]);
}
