#include "ft_printf.h"

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
	if (tab->width && !tab->dash)
		align(tab, tab->preci, ' ');
	tab->b_written += write(1, "%", 1);
	if (tab->width && tab->dash)
		align(tab, tab->preci, ' ');
}

int	print_format(t_printf *tab, char f)
{
	if (f == 'c')
		print_char(tab);
	if (f == '%' && tab->percent)
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
	if (f == 'x' || f == 'X' || f == 'o')
	{
		int	base;

		if (f == 'o')
			base = 8;
		else
			base = 16;
		print_xXo(tab, f, base);
	}
	return (tab->b_written);
}

