#include "ft_printf.h"

void	print_oXx_s(t_printf *tab, char f)
{
	if (f == 'x')
		tab->b_written += write(1, "0x", 2);
	else if (f == 'X')
		tab->b_written += write(1, "0X", 2);
}
int	ft_strlen_di(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (i + neg);
}

void print_di(t_printf *tab)
{
	char	*s;
	s = ft_itoa_base(special_cases_di(tab), 10);
	if (!tab->preci && *s == '0' && tab->dot)
		return ;
	tab->width -= ft_strlen(s) + (tab->sign || tab->space);
	tab->preci -= ft_strlen_di(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		s = align_di(tab, tab->width, ' ', s);
	else if (tab->sign && *s != '-')
		tab->b_written += write(1, "+", 1);
	else if (tab->space && *s != '-')
		tab->b_written += write(1, " ", 1);
	if (tab->preci > 0)
		s = align_di(tab, tab->preci, '0', s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	va_end(tab->args);
}

void print_o(t_printf *tab, int base)
{
	char	*s;

	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), base);
	else
		s = ft_itoa_base(special_cases_uox(tab), base);
	if (!tab->preci && *s == '0' && tab->dot && !tab->hash)
		return ;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s);
	if (tab->hash && tab->preci < 1 && *s != '0')
		tab->preci = 1; // Adding the 0 for the hash flag
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash && tab->zero)
			align_di(tab, tab->width, '0', s);
		else
			align_di(tab, tab->width, ' ', s);
	}
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	va_end(tab->args);
}

void print_xX(t_printf *tab, char f, int base)
{
	char	*s;

	tab->error = 0;
	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), base);
	else
		s = ft_itoa_base(special_cases_uox(tab), base);
	if (!tab->preci && *s == '0' && tab->dot)
			tab->error = 1;
	if (tab->hash && (tab->preci == 0 || tab->dash))
		s = conv_hash(tab, s, f);
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->error; // to add to width in case of error
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash && tab->zero)
		{
			tab->b_written += write(1, "0", 1);
			tab->b_written += write(1, &f, 1);
			align_di(tab, tab->width - 2, '0', s); // -2 to adjust the width for the previous character prints
		}
		else
			align_di(tab, tab->width, ' ', s);
	}
	if (tab->preci > 0)
	{
		if (tab->hash)
			print_oXx_s(tab, f);
		align_di(tab, tab->preci, '0', s);
	}
	while (*s && !tab->error)
	{
		if (f == 'X' && *s != '0') // 0 is a problem when returned from itoa_base
			*s = (char)ft_toupper(*s);
		tab->b_written += write(1, &*s++, 1);
	}
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	va_end(tab->args);
}

void print_u(t_printf *tab)
{
	char	*s;
	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), 10);
	else
		s = ft_itoa_base(special_cases_uox(tab), 10);
	if (!tab->preci && *s == '0' && tab->dot)
		return ;
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align_di(tab, tab->width, ' ', s);
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	if (*s == '-')
		++(*s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	va_end(tab->args);
}
