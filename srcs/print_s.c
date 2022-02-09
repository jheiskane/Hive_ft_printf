#include "ft_printf.h"

void print_s(t_printf *tab)
{
	char	*s;

	s = va_arg(tab->args, char *);
	//special_cases(tab, 1);
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->preci, ' ');
	va_end(tab->args);
}
