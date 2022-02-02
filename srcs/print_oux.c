#include "ft_printf.h"

void print_xXo(t_printf *tab, char f, int base)
{
	char	*s;

	//p = va_arg(tab->args, unsigned long);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_base(special_cases_di(tab), base);
	while (*s)
	{
		if (f == 'X')
			*s = (char)ft_toupper(*s);
		tab->b_written += write(1, &*s++, 1);
	}
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}

void print_u(t_printf *tab)
{
	char	*s;

	//p = va_arg(tab->args, unsigned long);
	if (tab->width && !tab->dash)
		right_align(tab, 1);
	s = ft_itoa_base(special_cases_di(tab), 10);
	if (*s == '-')
		++(*s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		left_align(tab, 1);
	va_end(tab->args);
}
