/**
 * PE 018: Maximal Path Sum I.
 * PE 067: Maximal Path Sum II.
 *
 * Both of these are in the same file. Running them both takes no time:
 *
 * real   0m0.019s
 * user   0m0.002s
 * sys    0m0.002s
 *
 * This uses fscanf for reading in the file for Problem 67.
 */

#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? a : b)
const int CASE1 = 4;
const int CASE2 = 15;
const int CASE3 = 100;

int main(void) 
{

    // Simple test case
    int grid1[][CASE1] = {
     {3},
     {7, 4},
     {2, 4, 6},
     {8, 5, 9, 3},
    };

    for (int x = CASE1-2; x >= 0; x--) {
        for (int y = 0; y <= x; y++) {
            grid1[x][y] += MAX(grid1[x+1][y], grid1[x+1][y+1]);
        }
    }
    printf("Maximal Sum for easy case: %d\n",grid1[0][0]);

    // Problem 18
    int grid2[][CASE2] = {
     {75},
     {95, 64},
     {17, 47, 82},
     {18, 35, 87, 10},
     {20,  4, 82, 47, 65},
     {19,  1, 23, 75,  3, 34},
     {88,  2, 77, 73,  7, 63, 67},
     {99, 65,  4, 28,  6, 16, 70, 92},
     {41, 41, 26, 56, 83, 40, 80, 70, 33},
     {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
     {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
     {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
     {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
     {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
     { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
    };

    for (int x = CASE2-2; x >= 0; x--) {
        for (int y = 0; y <= x; y++) {
            grid2[x][y] += MAX(grid2[x+1][y], grid2[x+1][y+1]);
        }
    }
    printf("Maximal Sum for Problem 18: %d\n",grid2[0][0]);

    // Problem 67 (now have to load this in a matrix)
    int grid3[CASE3][CASE3];
    FILE *f = fopen("files/pe067.txt", "r");
    for (int x = 0; x < CASE3; x++) {
        for (int y = 0; y <= x; y++) {
            fscanf(f, "%d", &grid3[x][y]);
        }
    }
    fclose(f);

    for (int x = CASE3-2; x >= 0; x--) {
        for (int y = 0; y <= x; y++) {
            grid3[x][y] += MAX(grid3[x+1][y], grid3[x+1][y+1]);
        }
    }
    printf("Maximal Sum for Problem 67: %d\n",grid3[0][0]);
}
