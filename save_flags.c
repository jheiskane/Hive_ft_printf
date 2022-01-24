#include "ft_printf.h"

/* Calculate precision from the number after the . sign */
int	calc_preci(t_printf *tab, const char *str, int i)
{
	int		j;
	char	*precision;

	j = 0;
	while (ft_isdigit(str[i]))
	{
		j++;
		i++;
	}
	precision = ft_strsub(str, 0, j);
	tab->preci = ft_atoi(precision);
	free(precision);
	return (i);
}

int	is_dot(t_printf *tab, const char *str, int i)
{
	if (str[i] == '.')
	{
		tab->dot = 1;
		i++;
		if (ft_isdigit(str[i]))
			i = calc_preci(tab, &str[i], i);
	}
	return (i);
}

int	is_space(t_printf *tab, const char *str, int i)
{
	if (str[i] == ' ')
		tab->space = 1;
	return (i + 1);
}

int	is_sign(t_printf *tab, const char *str, int i)
{
	if (str[i] == '-' || str[i] == '+')
		tab->percent = 1;
	return (i + 1);
}

int	is_hash(t_printf *tab, const char *str, int i)
{
	if (str[i] == '#')
		tab->dash = 1;
	return (i + 1);
}

int	is_percent(t_printf *tab, const char *str, int i)
{
	if (str[i] == '%')
		tab->percent = 1;
	return (i + 1);
}

int	is_zero(t_printf *tab, const char *str, int i)
{
	if (str[i] == '0')
		tab->zero = 1;
	return (i + 1);
}

int	is_l(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		tab->ll = 1;
		return (i + 2);
	}
	else if(str[i] == 'l')
		tab->l = 1;
	return (i + 1);
}

int	is_L(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'L')
		tab->L = 1;
	return (i + 1);
}

int	is_h(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tab->hh = 1;
		return (i + 2);
	}
	else if(str[i] == 'h')
		tab->h = 1;
	return (i + 1);
}

int	is_width(t_printf *tab, const char *str, int i) // NEEDS UPDATE TO ACTUAL WIDTH
{
	if (str[i] == '-')
		tab->dash = 1;
	return (i + 1);
}
