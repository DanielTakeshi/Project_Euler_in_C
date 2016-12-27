/**
 * PE 008: Largest Product in a Series. This took a while to figure out the
 * corret 'C-like' way to read a file character by character. I put the numbers
 * in pe008.txt and read using fgetc. I also had to use atoi(...) because
 * otherwise I was reading in characters and when multiplying together (with the
 * getProduct method) I ended up with the ASCII values instead of the real
 * values I wanted.
 *
 * The runtime is pretty fast:
 *
 * real 0m0.022s
 * user 0m0.002s
 * sys  0m0.002s
 */

#include <stdio.h>
#include <stdlib.h>

const int adjacentDigits = 13; // Test with 4 and 13
const int numChars = 1000;


void debugPrint(int *numArray) {
    /* Debug print to make sure numArray has correct numbers in it. */
    for (int i = 1; i <= numChars; i++) {
        printf("%d", numArray[i-1]);
        if (i % 50 == 0) {
            printf("\n");
        }
    }
}

long long getProduct(int *numArray, int startIndex) {
    /* Obtain product of sliding window of 13 (or 4) characters. */
    long long product = 1; 
    for (int i = 0; i < adjacentDigits; i++) {
        if (numArray[startIndex + i] == 0) {
            return 0;
        }
        product *= numArray[startIndex + i];
    }
    return product;
}

int main(void) 
{
    FILE *myFile;
    myFile = fopen("files/pe008.txt", "r");

    // We know it's 1000 characters. Let's put them in an array.
    int numArray[numChars];
    int i = 0;
    int c;
    while ((c = fgetc(myFile)) != EOF) {
        if (c != '\n') {
            numArray[i] = atoi(&c);
            i++;
        }
    }
    debugPrint(numArray);

    // Now scan via a sliding window.
    long long largestProduct = 0;
    for (int i = 0; i < numChars-adjacentDigits; i++) {
        long long product = getProduct(numArray, i);
        if (product > largestProduct) {
            largestProduct = product;
            printf("starting index i=%d, updating largest product, now %llu...\n", 
                i, largestProduct); 
        }
    }

    printf("largest product: %llu\n", largestProduct);
    fclose(myFile);
}
