#include "ft_printf.h"

void print_s(t_printf *tab)
{
	char	*s;

	s = va_arg(tab->args, char *);
	//special_cases(tab, 1);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
