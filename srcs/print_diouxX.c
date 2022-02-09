#include "ft_printf.h"

void	print_oXx_s(t_printf *tab, char f)
{
	if (f == 'x')
		tab->b_written += write(1, "0x", 2);
	else if (f == 'X')
		tab->b_written += write(1, "0X", 2);
}


void print_di(t_printf *tab)
{
	char	*s;

	s = ft_itoa_base(special_cases_di(tab), 10);
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->preci >= tab->width)
		tab->width -= tab->preci;
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

void print_o(t_printf *tab, int base)
{
	char	*s;

	s = ft_itoa_base(special_cases_uox(tab), base);
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s);
	if (tab->hash && tab->preci < 1 && *s != '0')
		tab->preci = 1; // Adding the 0 for the hash flag
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash && tab->zero)
			align(tab, tab->width, '0');
		else
			align(tab, tab->width, ' ');
	}
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}

void print_xX(t_printf *tab, char f, int base)
{
	char	*s;

	s = ft_itoa_base(special_cases_uox(tab), base);
	if (tab->hash && *s == '0' && tab->dot)
		return ;
	if (tab->hash && tab->preci == 0 && !tab->zero)
		s = conv_hash(tab, s, f);
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s);
	if (tab->preci >= tab->width)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash && tab->zero)
		{
			tab->b_written += write(1, "0", 1);
			tab->b_written += write(1, &f, 1);
			align(tab, tab->width - 2, '0'); // -2 to adjust the width for the previous character prints
		}
		else
			align(tab, tab->width, ' ');
	}
	if (tab->preci > 0)
	{
		if (tab->hash)
			print_oXx_s(tab, f);
		align(tab, tab->preci, '0');
	}
	while (*s)
	{
		if (f == 'X' && *s != '0') // 0 is a problem when returned from itoa_base
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
	if (tab->preci == 0 && *s == '0')
		return ;
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->preci >= tab->width)
		tab->width -= tab->preci;
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
