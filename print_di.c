#include "ft_printf.h"

void print_di(t_printf *tab)
{
	int				p;
	char			*s;

	p = va_arg(tab->args, int);
	//special_cases(tab, 1);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_base(p, 10);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
