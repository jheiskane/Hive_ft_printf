#include "ft_printf.h"

char	*save_to_str(double nb, int preci)
{
	char			*new;
	int				x;
	int				digit;
	double			tmp;

	x = 0;

	new = ft_strnew(preci);
	if (!new)
		return (NULL);
	while (x < preci)
	{
		tmp = nb * 10;
		digit = tmp;
		new[x++] = digit + '0';
		nb = tmp - digit;
	}
	return (new);
}

char	*ft_itoa_float(t_printf *tab, double nb)
{
	double			a_com;
	long long int	b_com;
	char			*new;

	b_com = nb;
	new = ft_itoa_base(b_com, 10);
	if (tab->dot && tab->preci == 0)
		return (new);
	if (tab->preci == 0)
		tab->preci = 6;
	a_com = nb - b_com;
	if (a_com)
	{
		// NEEDS ROUNDING IMPLEMENTED
		new = ft_strjoin(new, save_to_str(a_com, tab->preci));
	}
	return (new);
}
