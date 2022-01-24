#include "ft_printf.h"
#include <stdio.h>

t_printf	*ini_struct()
{
	t_printf	*tab;

	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		return (0);
	tab->dash = 0;
	tab->ret = 0;
	tab->percent = 0;
	tab->dot = 0;
	tab->preci = 0;
	tab->sign = 0;
	tab->space = 0;
	tab->width = 0;
	tab->zero = 0;
	tab->hh = 0;
	tab->L = 0;
	tab->ll = 0;
	tab->h = 0;
	tab->conversions = "udcsfupxX"; //allocate and free?
	return (tab);
}

int	save_format(t_printf *tab, int i, const char *str)
{
	while (!ft_strchr(tab->conversions, str[i]))
	{
		i = is_dot(tab, str, i); // sets precision as well
		i = is_sign(tab, str, i);
		i = is_hash(tab, str, i);
		i = is_space(tab, str, i);
		i = is_width(tab, str, i);
		i = is_h(tab, str, i);
		i = is_l(tab, str, i);
		i = is_width(tab, str, i);
		i = is_L(tab, str, i);
	}
	return (i);
}

void	chk_args(const char *input_str, t_printf *tab)
{
	int	i;

	i = 0;
	while (input_str[i])
	{
		if (input_str[i] == '%')
			i += save_format(tab, i + 1, input_str);
		else
			tab->ret += write(1, &input_str[i], 1);
		i++;
	}
}

int	ft_printf(const char *str_format, ...)
{
	t_printf	*tab;

	tab = ini_struct();
	chk_args(str_format, tab);

	return (tab->ret); // Return the number of bytes printed (write)
}

