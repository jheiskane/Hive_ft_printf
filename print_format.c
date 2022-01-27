#include "ft_printf.h"

void	print_percent(t_printf *tab)
{
	write (1, "%", 1);
	tab->b_written++;
}

int	print_format(t_printf *tab, char f)
{
	if (f == 'c')
		print_char(tab);
	if (f == '%')
		print_percent(tab);
	return (tab->b_written);
}
