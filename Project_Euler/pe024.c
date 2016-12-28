/**
 * PE 019: Lexicographic Permutations. Uses standard algorithm. Whew, at least
 * quicksort is ther in stdlib. I should think about how I can use this
 * procedure for future problems.
 *
 * real   0m0.071s
 * user   0m0.053s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <stdlib.h>

void printArray(int perm[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

int getLargestK(int perm[], int length) {
    int k = -1;
    int c = 0;
    while (c < length-1) {
        if (perm[c] < perm[c+1]) {
            k = c;
        }
        c++;
    }
    return k;
}

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main(void) 
{
    int length = 10;
    int perm[length];
    for (int i = 0; i < length; i++) {
        perm[i] = i;
    }

    int t = 1;
    int largestK = 0;
    while (1) {
        if (t == 1000000) {
            printArray(perm, length);
            break;
        }

        // Book-keeping
        largestK = getLargestK(perm, length);
        if (largestK == -1) break;
        int bestL = -1;
        for (int l = largestK+1; l < length; l++) {
            if (perm[largestK] < perm[l]) {
                bestL = l; 
            }
        }

        // Now modify perm
        int tmp = perm[largestK];
        perm[largestK] = perm[bestL];
        perm[bestL] = tmp;

        int rest = (length)-(largestK+1);
        if (rest > 1) {
            int tmpArray[rest];
            for (int i = largestK+1; i < length; i++) {
                tmpArray[i-(largestK+1)] = perm[i];
            }
            // Whew, thank goodness they have qsort in stdlib.
            qsort(tmpArray, rest, sizeof(int), compare);

            for (int i = largestK+1; i < length; i++) {
                perm[i] = tmpArray[i-(largestK+1)];
            }
        }

        t++;
    }
}
