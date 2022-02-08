#include "ft_printf.h"

void print_di(t_printf *tab)
{
	char	*s;

	s = ft_itoa_base(special_cases_di(tab), 10);
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}

void print_xXo(t_printf *tab, char f, int base)
{
	char	*s;

	s = ft_itoa_base(special_cases_uox(tab), base);
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	while (*s)
	{
		if (f == 'X')
			*s = (char)ft_toupper(*s);
		tab->b_written += write(1, &*s++, 1);
	}
	if (tab->width && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}

void print_u(t_printf *tab)
{
	char	*s;

	s = ft_itoa_base(special_cases_uox(tab), 10);
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	if (*s == '-')
		++(*s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}
