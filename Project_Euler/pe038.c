/**
 * PE 038: Pandigital Multiples. Pencil and Paper:
 *
 * The number to beat is 918273645. We know that our integer that we're
 * multiplying must start with a 9 since we have to multiply it by 1 first. So
 * we're left with numbers of the form 9X, 9XY, 9XYZ where X,Y,Z represent
 * DIFFERENT digits (since we need 1,2,...,9 all represented in the final
 * number). We clearly can't use a 5-digit number since we have to use (1,...,n)
 * where n>1. 
 *
 * Upon further inspection, we cannot use any numbers of the form 9XY, because
 * the second multiple results in a four digit number, hence 3+4=7 and the 9XY*3
 * will not be able to fit inside the two remaining digits. That leaves numbers
 * of the form 9X and 9XYZ as our integer which we multiply with 1,2,...,n.
 *
 * We ALSO cannot use any 9X numbers because the second and third multiples take
 * up six digits together, which leaves one digit remaining for 9X*4. Thus, we
 * know our number is now 9XYZ where X =/= Y =/= Z. Our lower bound is 9012
 * (well, 9182 from the example) and our uppper bound is 9876. Since 9876*2 =
 * 19752, we have to decrease the number enough so that the '9' there goes away.
 * (Note that we KNOW our fifth digit will be 1, i.e. we have 9___1____ as our
 * result, where I've now used empty spaces to represent the unique digits that
 * will be there.
 *
 * We see that since 9500*2 = 19000, our bounds are now (9182,9487) for our
 * starting integer. 9182*2 and 9487*2 both result in a number 18___, so we
 * conclude that we cannot escape '8' there (or a '1' for that matter) so our
 * starting integers cannot contain an 8, our bounds are now (9234,9476).
 *
 * Let's continue. 9476*2 = 18952 so we have to derease it to knock out the '9'
 * there. 9450*2 = 18900 so that will get rid of the 9 but leave another 8
 * there, so keep going, 9400*2 = 18800, so we have to go lower and using our
 * other constraints, we get (9234,9376) as our new bounds.
 *
 * 9376*2 = 18752 with an extra 7 there so let's keep decreasing the number.
 * 9350*2 = 18700 so using other constraints again, our newer bounds are
 * (9234,9347).
 *
 * Keep going with constraints and we eventually get 9237 as a valid candidate.
 * Yay!
 */

#include <stdio.h>

int main(void) 
{
    printf("pencil and paper\n");
}
