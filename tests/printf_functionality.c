#include <stdio.h>


/*   The overall syntax of a conversion specification is:

	%[$][flags][width][.precision][length modifier]conversion



*/

int main()
{
	printf("The * functionality %*d", 1, 2); // prints 2. * asks for the next one


	/*Precision   */
	printf("\nPrecision\n");
	printf("\nPrints 3 decimal places from 12.1355555 -> %.3f", 12.1355555); // Prints 2 decimal places only and rounds to closest and even
	printf("\nPrecision with integer \n");
	printf("\nPrints 3 precision places from 1209 -> %.5d", 1209);




	printf("\nWidth:%10.2f", 30.300);			   // "10" Here means that there is at minimum 10 spaces used. So if you print just "1" it would print "         1".
	printf("\n%2$*1$d", 3, 1); 					   // Prints "  1"


	/* Flags */

	printf("\n%#x", -10); 					   // #is alternative form so the input is converted to alternative form. for example here decimal 10 is converted to hexadecimal aka. "0xa"
	printf("\n%######x", 10);					// Note that multiple flags dont affect the print out. Still prints "0xa"
	printf("\n%#x", 10);
}
