/**
 * PE 013: Large sum. Wowza! If this were Java, I'd use BigInteger. But I guess
 * for C I'll just brute force using arrays. This is what the solution does, it
 * tries explicitly using arrays to form the addition, where each array element
 * is a character (or digit) inside the number. That should mimic how BigInteger
 * works, I think.
 * 
 * real   0m0.025s
 * user   0m0.002s
 * sys    0m0.002s
 *
 * NOTE: I keep getting complaints about the loading with atoi, etc. For now I
 * guess its OK but eventually I shoudl figure out how to resolve this.
 */

#include <stdlib.h>
#include <stdio.h>


void debugPrint(int grid[][50]) {
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 50; y++) {
            printf("%d", grid[x][y]);
        }
        printf("\n");
    }
}


int getColumnSum(int grid[][50], int column) {
    int sum = 0;
    for (int x = 0; x < 100; x++) {
        sum += grid[x][column];
    }
    return sum;
}


int main(void) 
{
    // Load data into 'grid'.
    FILE *myFile = fopen("files/pe013.txt", "r");
    int grid[100][50];
    int x = 0;
    int y = 0;
    int c;
    while ((c = fgetc(myFile)) != EOF) {
        if (c != '\n') {
            grid[x][y] = atoi(&c);
            y++;
        } else {
            y = 0;
            x++;
        }
    }
    fclose(myFile);
    //debugPrint(grid);

    // Now perform the addition. Decrement from last digit.
    // A bit confusing, we'll be putting values in 'result' in REVERSE order, so
    // least significant digit first, etc.
    int carryOver = 0;
    int result[50];  // I think OK, will only have 1-3 digits of carry-over.
    int columnSum;
    for (int i = 49; i >= 0; i--) {
        columnSum = getColumnSum(grid, i) + carryOver;
        printf("col=%d, colSum(w/carry)=%d\n", i, columnSum);
        result[i] = columnSum % 10;
        carryOver = columnSum / 10;
    }

    // Print 'result' in reverse order but don't forget carry-over.
    for (int i = 0; i < 50; i++) {
        printf("%d", result[i]);
    }
    printf("\n");
    printf("final carry over:%d\n", carryOver);
    printf("so concatenate %d to result at beginning to get final answer", 
        carryOver/10);
}
