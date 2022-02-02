#include "ft_printf.h"


void	right_align(t_printf *tab, int len)
{
	while(tab->width > len)
	{
		write(1, " ", 1);
		len++;
	}
	tab->b_written += len - 1;
}

void	left_align(t_printf *tab, int len)
{
	while(tab->width > len)
	{
		write(1, " ", 1);
		len++;
	}
	tab->b_written += len - 1;
}

size_t	special_cases_di(t_printf *tab)
{
	if (tab->hh)
		return ((signed char)va_arg(tab->args, size_t));
	else if (tab->ll)
		return ((long long int)va_arg(tab->args, size_t));
	else if (tab->l)
		return ((long int)va_arg(tab->args, size_t));
	else if (tab->h)
		return ((short int)va_arg(tab->args, size_t));
	return (va_arg(tab->args, size_t));
}

double	special_cases_f(t_printf *tab)
{
	if (tab->l)
		return ((long double)va_arg(tab->args, double));
	else if (tab->L)
		return ((long double)va_arg(tab->args, double));
	return (va_arg(tab->args, double));
}
