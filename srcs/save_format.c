#include "ft_printf.h"

/* Calculate precision from the number after the . sign */
int	calc_preci(t_printf *tab, const char *str, int i)
{
	int		j;
	char	*precision;

	j = 0;
	while (ft_isdigit(str[j]))
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
	{
		tab->space = 1;
		i++;
	}
	return (i);
}

int	is_sign(t_printf *tab, const char *str, int i)
{
	if (str[i] == '+')
	{
		tab->sign = 1;
		i++;
	}
	return (i);
}

int	is_hash(t_printf *tab, const char *str, int i)
{
	if (str[i] == '#')
	{
		tab->hash = 1;
		i++;
	}
	return (i);
}

int	is_percent(t_printf *tab, const char *str, int i)
{
	if (str[i] == '%')
	{
		tab->percent = 1;
		i++;
	}
	return (i);
}

int	is_zero(t_printf *tab, const char *str, int i)
{
	if (str[i] == '0')
	{
		tab->zero = 1;
		i++;
	}
	return (i);
}

int	is_l(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		tab->ll = 1;
		return (i + 2);
	}
	else if(str[i] == 'l')
	{
		tab->l = 1;
		i++;
	}
	return (i);
}

int	is_L(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'L')
	{
		tab->L = 1;
		i++;
	}
	return (i);
}

int	is_h(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tab->hh = 1;
		return (i + 2);
	}
	else if (str[i] == 'h')
	{
		tab->h = 1;
		i++;
	}
	return (i);
}

int	is_dash(t_printf *tab, const char *str, int i)
{
	if (str[i] == '-')
	{
		tab->dash = 1;
		i++;
	}
	return (i);
}

int	is_width(t_printf *tab, const char *str, int i)
{
	int		j;
	char	*numb;

	if (ft_isdigit(str[i]))
	{
		j = 0;
		while (ft_isdigit(str[i + j]))
			j++;
		numb = ft_strnew(j);
		ft_strncpy(numb, &str[i], j);
		tab->width = ft_atoi(numb);
		free (numb);
		return (i + j);
	}
	return (i);
}

