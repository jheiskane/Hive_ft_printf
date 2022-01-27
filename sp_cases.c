#include "ft_printf.h"


void	right_align(t_printf *tab, int len)
{
	while(tab->width > len)
	{
		write(1, " ", 1);
		len++;
	}
}

void	left_align(t_printf *tab, int len)
{
	while(tab->width > len)
	{
		write(1, " ", 1);
		len++;
	}
}


// void	special_cases(t_printf *tab, int len)
// {


// }
