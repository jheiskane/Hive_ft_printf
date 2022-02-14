#include "ft_printf.h"

void print_s(t_printf *tab)
{
	int		len;
	char	*p;

	len = 1;
	p = va_arg(tab->args, char *);
	tab->zero = 0;
	if (!p)
	{
		tab->b_written += write(1, "(null)", 6);
		return ;
	}
	if (tab->dot && tab->preci < ft_strlen(p))
		tab->width -= tab->preci;
	else
		tab->width -= ft_strlen(p);
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0 || tab->dot)
		len = tab->preci;
	while (*p && len != 0)
	{
		if (tab->preci > 0 || tab->dot)
			len--;
		tab->b_written += write(1, &*p++, 1);
	}
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}
