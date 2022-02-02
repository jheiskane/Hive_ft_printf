#include "ft_printf.h"

void print_char(t_printf *tab)
{
	char a;

	a = va_arg(tab->args, int);
	//special_cases(tab, 1);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	tab->b_written += write(1, &a, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
