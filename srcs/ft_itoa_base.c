/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/04 13:12:30 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long int nb, int base)
{
	char			*new;
	long long int	i;
	int				x;
	long long int	rem;
	int				neg;

	neg = 0;
	x = 0;
	if (nb == 0)
		return ("0");
	if (nb < 0 && base == 10)
	{
		neg = 1;
		nb *= -1;
		x++;
	}
	i = nb;
	while (i > 0)
	{
		i = i / base;
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
	return (new);
}
