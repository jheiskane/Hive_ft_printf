#include <stdio.h>
#include <stdarg.h>
#include "../ft_printf.h"

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
	float b;
	char c;


	a = 42;
	c = '*';

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


	// /* Plain pointer */
	// printf("\nPlain pointer\n");
	// printf("ft_printf: \n");
	// ft_printf("%p\n", a);
	// printf("\nReal printf: \n");
	// printf("%lld\n", a);


	// 	/* Length modifiers */
	printf("\nll modifier\n");
	printf("ft_printf: \n");
	ft_printf("%lld\n", a);
	printf("\nReal printf: \n");
	printf("%lld\n", a);

	printf("\nPlain int\n");
	printf("ft_printf:\n");
	ft_printf("%lli", a);
	//ft_printf("%llp\n", a);
	printf("\nReal printf: \n");
	printf("%lli\n", a);



	/* Plain int */
	printf("\nPlain int\n");
	printf("ft_printf:\n");
	ft_printf("%lli", a);
	//ft_printf("%llp\n", a);
	printf("\nReal printf: \n");
	printf("%lli\n", a);






















	// /* Invalid inputs */
	// printf("\nInvalid inputs...\n");
	// ft_printf("0123456789%0.3c %c?", a, a); // defined behivior
	// printf("\nReal printf: \n");
	// printf("0123456789%0.3c %c?", a, a); // Undefined behavior, should this be fixed?
	// printf("\nend\n");



}


