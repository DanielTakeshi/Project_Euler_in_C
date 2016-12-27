/**
 * PE 011: Longest product in grid. Uses files/pe011.txt with the text file
 * containing numbers. I'll put things in grid, fortunately C lets us have
 * int[][] types. This time fgetc would be harder because each number consists
 * of TWO characters.
 *
 * real   0m0.025s
 * user   0m0.002s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <stdlib.h>

const int LENGTH = 4;


void debugPrint(int array[][20]) {
    /* Learned something new, you can ignore first dimension: int[][20]. */
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }
}


int getLargestProduct(int grid[][20], int x, int y) {
    /**
     * This will go through the different cases. There's definitely a better way
     * than doing this brute force. Actually I'm not sure if the comments here
     * on directions are that correct but all that matters is that we cover all
     * directions with correct array bounds checking. You know, I could have
     * probably padded this with 0s to avoid these special cases, kind of like
     * padding 0s for convolutions.
     *
     * Here's a better option: we can encode these 8 cases in a for loop and
     * have a separate method which returns one of the 8 directions to go. That
     * will shorten the code a lot.
     */
    int largest = 0;

    if (x >= LENGTH-1) { // UP
        int prod = grid[x][y]*grid[x-1][y]*grid[x-2][y]*grid[x-3][y];
        if (prod > largest) largest = prod;
    }
    if (y >= LENGTH-1) { // LEFT
        int prod = grid[x][y]*grid[x][y-1]*grid[x][y-2]*grid[x][y-3];
        if (prod > largest) largest = prod;
    }
    if (y <= 20-LENGTH) { // RIGHT
        int prod = grid[x][y]*grid[x][y+1]*grid[x][y+2]*grid[x][y+3];
        if (prod > largest) largest = prod;
    }
    if (x <= 20-LENGTH) { // RIGHT
        int prod = grid[x][y]*grid[x+1][y]*grid[x+2][y]*grid[x+3][y];
        if (prod > largest) largest = prod;
    }

    if (x >= LENGTH-1 && y >= LENGTH-1) { // UP LEFT
        int prod = grid[x][y]*grid[x-1][y-1]*grid[x-2][y-2]*grid[x-3][y-3];
        if (prod > largest) largest = prod;
    }
    if (x <= 20-LENGTH && y >= LENGTH-1) { // UP RIGHT
        int prod = grid[x][y]*grid[x+1][y-1]*grid[x+2][y-2]*grid[x+3][y-3];
        if (prod > largest) largest = prod;
    }
    if (x >= LENGTH-1 && y <= 20-LENGTH) { // DOWN LEFT
        int prod = grid[x][y]*grid[x-1][y+1]*grid[x-2][y+2]*grid[x-3][y+3];
        if (prod > largest) largest = prod;
    } 
    if (x <= 20-LENGTH && y <= 20-LENGTH) { // DOWN RIGHT
        int prod = grid[x][y]*grid[x+1][y+1]*grid[x+2][y+2]*grid[x+3][y+3];
        if (prod > largest) largest = prod;
    }

    return largest;
}


int main(void) 
{
    FILE *myFile;
    myFile = fopen("files/pe011.txt", "r");
    int grid[20][20];

    // This seems to work, looks like I should learn more about fscanf.
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            fscanf(myFile, "%d", &grid[x][y]);
        }
    }
    debugPrint(grid);
    fclose(myFile);

    // Now let's find the largest product in the grid!
    int largestProduct = 0;
    for (int x = 0; x < 20; x++) {
        for (int y = 0; y < 20; y++) {
            if (grid[x][y] != 0) {
                int product = getLargestProduct(grid, x, y);
                if (product > largestProduct) {
                    largestProduct = product;
                    printf("product=%d is new largest at (x,y)=(%d,%d)\n",
                        product, x, y); 
                }
            }
        }
    }
}
