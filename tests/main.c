#include <stdio.h>
#include <stdarg.h>
int	ft_printf (const char *str_format, ...);

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


	a = 42;

	// /* Plain char with extra %*/
	// printf("ft_printf: \n");
	// ft_printf("123456789%%c", a);
	// printf("\nReal printf: \n");
	// printf("123456789%%c", a);
	// printf("\n\nend\n\n");

	// /* Plain char + alignments */
	// printf("ft_printf: \n");
	// ft_printf("0123456789%10c aligned?", a);
	// printf("\nReal printf: \n");
	// printf("0123456789%10c aligned?", a);
	// printf("\nend\n");

	/* Plain char + left alignments */
	printf("ft_printf: \n");
	ft_printf("0123456789%-10c aligned?", a);
	printf("\nReal printf: \n");
	printf("0123456789%-10c aligned?", a);
	printf("\nend\n");
}
