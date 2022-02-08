#include "ft_printf.h"

void print_f(t_printf *tab)
{
	char	*s;
	s = ft_itoa_float(tab, special_cases_f(tab));
	tab->width -= ft_strlen(s);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->preci, ' ');
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->preci, ' ');
	va_end(tab->args);
}
