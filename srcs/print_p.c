#include "ft_printf.h"

void print_p(t_printf *tab)
{
	unsigned long	p;
	char			*s;

	p = va_arg(tab->args, unsigned long);
	//special_cases(tab, 1);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_base(p, 16);
	write(1, "0x", 2);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
