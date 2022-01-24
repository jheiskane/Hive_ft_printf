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


	a = 20000;
	ft_printf("%d", a);
}
