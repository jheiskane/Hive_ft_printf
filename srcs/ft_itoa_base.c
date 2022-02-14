/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/14 18:27:34 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	check_min(long long int nb, char *min)
{
	if (nb < -9223372036854775807)
	{
		nb /= 10;
		*min = 'M';
	}
	return (nb);
}

char	*ft_itoa_base(long long int nb, int base)
{
	char			*new;
	char			min;
	int				x;
	long long int	rem;
	int				neg;

	neg = 0;
	x = 0;
	min = '0';
	if (nb == 0)
		return ("0");
	if (nb < 0 && base == 10)
	{
		neg = 1;
		nb = check_min(nb, &min);
		nb *= -1;
		x++;
	}
	rem = nb;
	while (rem > 0)
	{
		rem = rem / base;
		x++;
	}
	new = ft_strnew(x);
	if (!new)
		return (NULL);
	if (neg == 1)
		new[0] = '-';
	while (x > neg)
	{
		rem = 0;
		rem = nb % base;
		if (rem > 9)
			new[--x] = rem - 10 + 'a';
		else if (rem < 10)
			new[--x] = rem + '0';
		nb /= base;
	}
	if (min == 'M')
		new[19] = '8';
	return (new);
}
