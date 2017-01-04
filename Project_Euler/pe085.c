/**
 * PE 085: Counting rectangles. Given an (n,m) grid, the number of rectangles in
 * it is specified as:
 *
 *  (n+1 choose 2) * (m+1 choose 2)
 *
 * "Proof": A rectangle is specified by picking any two points (_not_ the grids
 * but the points that form the grid ... a bit confusing) on the x-axis and any
 * two points on the y-axis. If you pick those four points and then draw the
 * rectangle that is embedded in their intersection, you get the corresponding
 * rectangle. This completely specifies the rectangles, and since the number of
 * points is one more than the number of grid elements in both dimensions, and
 * we're picking any two of those points, the formula above follows.
 *
 * Runtime is fast:
 *
 * real   0m0.019s
 * user   0m0.001s
 * sys    0m0.002s
 */

#include <stdio.h>
#include <stdlib.h>
int const TARGET = 2000000;

int main(void) 
{
    int closestN = -1; 
    int closestM = -1; 
    int closestDiff = TARGET;
    int thisRect;
    int thisDiff;

    for (int n = 1; n < 100; n++) {
        for (int m = n; m < 100; m++) {
            thisRect = (n*(n+1)*m*(m+1)) / 4.0;
            thisDiff = abs(thisRect-TARGET);
            if (thisDiff < closestDiff) {
                closestN = n;
                closestM = m;
                closestDiff = thisDiff;
            }
        }
    }

    printf("closest (N,M) = (%d,%d)\n", closestN, closestM);
    printf("has %d rectangles\n", (closestN*closestM*(closestN+1)*(closestM+1))/4);
    printf("area = %d\n", closestN*closestM);
}
