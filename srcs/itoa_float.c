/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:48:11 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/25 11:16:32 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	round_nb(long double nb, int preci)
{
	long double	round;
	double		digit;
	int			d;
	int			x;

	digit = 0;
	round = 0.5;
	if (nb < 0)
		round = -0.5;
	x = 0;
	while (x < preci)
	{
		round /= 10;
		x++;
		d = nb / 10;
	}
	if (preci == 0)
	{
		d = nb;
	}
	digit = nb - d;
	if (digit == 0.5 && d % 2 == 0)
		return (nb - round);
	return (nb + round);
}

char	*save_to_str(long double a_com, int preci)
{
	char			*new;
	int				x;
	int				digit;
	long double		tmp;

	x = 1;
	new = ft_strnew(preci + 1);
	while (x <= preci)
	{
		new[0] = '.';
		tmp = a_com * 10;
		digit = tmp;
		new[x++] = digit + '0';
		a_com = tmp - digit;
	}
	return (new);
}

char	*handle_nan_infinity(long double nb)
{
	if (nb == 1.0 / 0)
		return (ft_strdup("inf"));
	if (!(nb == nb))
		return (ft_strdup("nan"));
	return (ft_strdup("-inf"));
}

char	*ft_itoa_float(t_printf *tab, long double nb)
{
	long double		a_com;
	long long int	b_com;
	char			*new;
	int				neg_zero;

	neg_zero = nb == (0 && 1 / nb < 0);
	if (!tab->dot)
		tab->preci = 6;
	if (nb == 1.0 / 0 || nb == -1.0 / 0 || !(nb == nb))
		return (handle_nan_infinity(nb));
	nb = round_nb(nb, tab->preci);
	b_com = nb;
	new = ft_itoa_ll(b_com);
	a_com = ft_abs(nb) - ft_abs(b_com);
	new = ft_joindel(new, save_to_str(a_com, tab->preci));
	if (neg_zero)
		new = ft_joindel(ft_strdup("-"), new);
	return (new);
}
