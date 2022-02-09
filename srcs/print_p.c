#include "ft_printf.h"

void print_p(t_printf *tab)
{
	unsigned long	p;
	char			*s;

	p = va_arg(tab->args, unsigned long);
	s = ft_itoa_base(p, 16);
	tab->width -= ft_strlen(s);
	//special_cases(tab, 1);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->preci, ' ');
	write(1, "0x", 2);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->preci, ' ');
	va_end(tab->args);
}
