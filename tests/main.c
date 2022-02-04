#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

// void v_printf(int count, ...)
// {
//     va_list args;
//     int i;
//     va_start(args, count);
//     printf ("variadic : argument count = %d\n", count);
//     for (i = 0; i < count; i++) {
//      printf("argument %d = %d, ", i + 1, va_arg(args, int));
//     }
//     printf ("\n");
//     va_end(args);
// }

int main()
{
	int	a;
	//float b;
	char c;
	long long int l;


	a = 136;
	c = '*';
	l = 1330000033333330033;
	// /* Plain char with extra %*/
	// printf("\nPlain char with extra %%\n");
	// printf("ft_printf: \n");
	// ft_printf("123456789%%c", a);
	// printf("\nReal printf: \n");
	// printf("123456789%%c", a);


	// /* Plain char + alignments */
	// printf("\nPlain char + alignments\n");
	// printf("ft_printf: \n");
	// ft_printf("0123456789%10c aligned?", a);
	// printf("\nReal printf: \n");
	// printf("0123456789%10c aligned?", a);


	// /* Plain char + left alignments */
	// printf("\nPlain char + left alignments\n");
	// printf("ft_printf: \n");
	// ft_printf("0123456789%-10c aligned?", a);
	// printf("\nReal printf: \n");
	// printf("0123456789%-10c aligned?", a);


	// /* Plain string + left alignments */
	// printf("\nPlain string + left alignments\n");
	// printf("ft_printf: \n");
	// ft_printf("123456789%s", "Okaydokay");
	// printf("\nReal printf: \n");
	// printf("123456789%s", "Okaydokay");


	/* Plain pointer */
	// printf("\nPlain pointer\n");
	// printf("ft_printf: \n");
	// //ft_printf("%v\n", a);
	// printf("\nReal printf: \n");
	// printf("%v\n", a);


 	/* Length modifiers */
	// printf("\nhh modifier\n");
	// printf("ft_printf: \n");
	// ft_printf("%hhd\n", c);
	// printf("\nReal printf: \n");
	// printf("%hhd\n", c);

	// printf("\nll modifier\n");
	// printf("ft_printf: \n");
	// ft_printf("%lld\n", l);
	// printf("\nReal printf: \n");
	// printf("%lld\n", l);


	// printf("\nh modifier\n");
	// printf("ft_printf: \n");
	// ft_printf("%hd%hd", (short int)0, (short int)42);
	// printf("\nReal printf: \n");
	// printf("%hd%hd", (short int)0, (short int)42);

	// printf("\nh negative SHORT MIN modifier\n");
	// printf("ft_printf: \n");
	// ft_printf("%hd%hd", (short int)-32768, (short int)42);
	// printf("\nReal printf: \n");
	// printf("%hd%hd", (short int)-32768, (short int)42);


	// printf("\nPlain int\n");
	// printf("ft_printf:\n");
	// ft_printf("%lli", a);
	// //ft_printf("%llp\n", a);
	// printf("\nReal printf: \n");
	// printf("%lli\n", a);



	// /* Plain int */
	// printf("\nPlain int\n");
	// printf("ft_printf:\n");
	// ft_printf("%lli", a);
	// //ft_printf("%llp\n", a);
	// printf("\nReal printf: \n");
	// printf("%lli\n", a);

	// /* Width without conversion */
	// printf("\nWidth without conversion\n");
	// printf("ft_printf:\n");
	// printf("return value = %d", ft_printf("%5%"));
	// printf("\nReal printf: \n");
	// printf("return value = %d", printf("%5%"));



	// /* Width without conversion */
	// printf("\nWidth without conversion\n");
	// printf("ft_printf:\n");
	// printf("return value = %d", ft_printf("%5%"));
	// printf("\nReal printf: \n");
	// printf("return value = %d", printf("%5%"));



	// /* Plain X x */
	// a = 13;
	// printf("\nPlain X\n");
	// printf("ft_printf: \n");
	// ft_printf("%X\n", a);
	// printf("\nReal printf: \n");
	// printf("%X\n", a);

	// printf("\nPlain X\n");
	// printf("ft_printf: \n");
	// ft_printf("%x\n", a);
	// printf("\nReal printf: \n");
	// printf("%x\n", a);
	// a = 42;

	// /* Plain o */
	// printf("\nPlain o\n");
	// printf("ft_printf: \n");
	// ft_printf("%o\n", 9);
	// printf("\nReal printf: \n");
	// printf("%o\n", 9);

	// /* Plain u */
	// printf("\nPlain u\n");
	// printf("ft_printf: \n");
	// ft_printf("%u\n", -1);
	// printf("\nReal printf: \n");
	// printf("%u\n", -1);


	/* Plain f */
	double f;

	// f = 123.123;
	// printf("\nPlain f\n");
	// printf("ft_printf: \n");
	// ft_printf("%.1f\n", f);
	// printf("\nReal printf: \n");
	// printf("%.1f\n", f);

	f = 1235557891011.0;

	printf("\nPlain f\n");
	printf("ft_printf: \n");
	ft_printf("%.1f\n", f);
	printf("\nReal printf: \n");
	printf("%.1f\n", f);

	printf("\nPlain f\n");
	printf("ft_printf: \n");
	ft_printf("%.15f\n", f);
	printf("\nReal printf: \n");
	printf("%.15f\n", f);

	printf("\nPlain f\n");
	printf("ft_printf: \n");
	ft_printf("%.10f\n", f);
	printf("\nReal printf: \n");
	printf("%.10f\n", f);


	printf("\nPlain f\n");
	printf("ft_printf: \n");
	ft_printf("%.10f, %d, %c, %s\n", f, 123456789, 42, "Hello World!");
	printf("\nReal printf: \n");
	printf("%.10f\n", f);








	// /* Invalid inputs */
	// printf("\nInvalid inputs...\n");
	// ft_printf("0123456789%0.3c %c?", a, a); // defined behivior
	// printf("\nReal printf: \n");
	// printf("0123456789%0.3c %c?", a, a); // Undefined behavior, should this be fixed?
	// printf("\nend\n");



}


