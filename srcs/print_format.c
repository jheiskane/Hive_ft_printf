#include "ft_printf.h"

char	*conv_hash(t_printf *tab, char *str, char f)
{
	char *tmp;

	tmp = str;
	if (tab->hash && *str != '0')
	{
		if (f == 'X')
			str = ft_strjoin("0x", str);
		else if (f == 'x')
			str = ft_strjoin("0x", str);
		free (tmp);
	}
	return (str);
}

char	*align_di(t_printf *tab, int len, char c, char *s)
{
	int	i;

	i = 0;
	if ((tab->zero && !tab->dot) || c == '0') // If printing zeros before the number, add '-' before the zeros
	{
		if (*s == '-')
			tab->b_written += write(1, &*s++, 1);
		else if (tab->sign)
		{
			tab->b_written += write(1, "+", 1);
			//len--;
		}
		else if (tab->space)
			tab->b_written += write(1, " ", 1);
	}
	if (tab->zero && !tab->dot && !tab->dash)
		c = '0';
	while(len > i)
	{
		write(1, &c, 1);
		i++;
	}
	if (c == ' ' && *s == '-')
		tab->b_written += write(1, &*s++, 1);
	tab->b_written += len;
	return (s);
}

char	*align_f(t_printf *tab, int len, char c, char *s)
{
	int	i;

	i = 0;
	if (tab->zero) // If printing zeros before the number, add '-' before the zeros
	{
		if (*s == '-')
			tab->b_written += write(1, &*s++, 1);
		else if (tab->sign)
		{
			tab->b_written += write(1, "+", 1);
			len--;
		}
		else if (tab->space || *s == '0')
			tab->b_written += write(1, " ", 1);
	}
	if (tab->zero && !tab->dash)
		c = '0';
	while(len > i)
	{
		write(1, &c, 1);
		i++;
	}
	if (!tab->zero && *s == '-')
		tab->b_written += write(1, &*s++, 1);
	tab->b_written += len;
	return (s);
}


void	align(t_printf *tab, int len, char c)
{
	int	i;

	i = 0;
	if (tab->zero)
		c = '0';
	while(len > i)
	{
		write(1, &c, 1);
		i++;
	}
	tab->b_written += len; //len - 1 deleted
}

void	print_percent(t_printf *tab)
{
	//special_cases(tab, 1);
	tab->width -= 1;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	tab->b_written += write(1, "%", 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
}

int	print_format(t_printf *tab, char f)
{
	if (f == 'c')
		print_char(tab);
	if (f == '%')
		print_percent(tab);
	if (f == 'd' || f == 'i')
		print_di(tab);
	if (f == 's')
		print_s(tab);
	if (f == 'p')
		print_p(tab);
	if (f == 'u')
		print_u(tab);
	if (f == 'f')
		print_f(tab);
	if (f == 'x' || f == 'X')
		print_xX(tab, f, 16);
	if (f == 'o')
		print_o(tab, 8);
	return (tab->b_written);
}

