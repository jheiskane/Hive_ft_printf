#include "ft_printf.h"

int	print_format(t_printf *tab, char f)
{
	if (f == 'c')
		print_char(tab);

	return (tab->b_written);
}
