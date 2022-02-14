#include "ft_printf.h"

void print_p(t_printf *tab)
{
	unsigned long	p;
	char			*s;
	char			*tmp;

	p = (unsigned long)va_arg(tab->args, size_t);
	s = ft_itoa_base(p, 16);
	tmp = s;
	if (tab->dot && tab->preci == 0 && !p)
	{
		tab->b_written += write(1, "0x", 2);
	 	return ;
	}
	tab->width -= ft_strlen(s) + 2;
	tab->preci -= ft_strlen(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	tab->b_written += write(1, "0x", 2);
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	if (*s == '-')
		++(*s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	if (*tmp && *tmp != '0')
		free (tmp);
	va_end(tab->args);
}
