#include "ft_printf.h"

long double	round_nb(long double nb, int preci)
{
	long double	round;
	int 	x;

	round = 0.5;
	if (nb < 0)
		round = -0.5;
	x = 0;
	while (x < preci)
	{
		round /= 10;
		x++;
	}
	return (nb + round);
}

char	*save_to_str(long double a_com, int preci)
{
	char			*new;
	int				x;
	int				digit;
	long double			tmp;

	x = 0;

	new = ft_strnew(preci);
	if (!new)
		return (NULL);
	new[x++] = '.';
	while (x <= preci)
	{
		tmp = a_com * 10;
		digit = tmp;
		new[x++] = digit + '0';
		a_com = tmp - digit;
	}
	return (new);
}

char	*ft_itoa_float(t_printf *tab, long double nb)
{
	long double				a_com;
	long long int			b_com;
	char					*new;

	b_com = nb;
	new = ft_itoa_base(b_com, 10);
	if (tab->dot && tab->preci == 0)
		return (new);
	if (tab->preci == 0)
		tab->preci = 6;
	nb = round_nb(nb, tab->preci);
	a_com = ft_abs(nb) - ft_abs(b_com);
	new = ft_strjoin(new, save_to_str(a_com, tab->preci));
	return (new);
}
