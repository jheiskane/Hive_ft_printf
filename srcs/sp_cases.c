#include "ft_printf.h"

size_t	special_cases_di(t_printf *tab)
{
	if (tab->hh)
		return ((signed char)va_arg(tab->args, size_t));
	else if (tab->ll)
		return ((long long int)va_arg(tab->args, long long int));
	else if (tab->l)
		return ((long int)va_arg(tab->args, size_t));
	else if (tab->h)
		return ((short int)va_arg(tab->args, size_t));
	return (va_arg(tab->args, int));
}

double	special_cases_f(t_printf *tab)
{
	if (tab->l)
		return ((long double)va_arg(tab->args, double));
	else if (tab->L)
		return ((long double)va_arg(tab->args, double));
	return (va_arg(tab->args, double));
}

unsigned int	special_cases_uox(t_printf *tab)
{
	if (tab->hh)
		return ((unsigned char)va_arg(tab->args, int));
	else if (tab->ll)
		return ((unsigned long long int)va_arg(tab->args, unsigned long long int));
	else if (tab->l)
		return ((unsigned long int)va_arg(tab->args, unsigned long int));
	else if (tab->h)
		return ((unsigned short int)va_arg(tab->args, int));
	return (va_arg(tab->args, unsigned int));
}
