#include "ft_printf.h"

void print_di(t_printf *tab)
{
	char	*s;

	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_base(special_cases_di(tab), 10);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}

void print_f(t_printf *tab)
{
	char	*s;

	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_float(tab, special_cases_f(tab));
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
