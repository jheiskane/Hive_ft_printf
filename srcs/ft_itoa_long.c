/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/07 13:37:14 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_ll(ssize_t nb)
{
	char	*new;
	int		x;
	ssize_t	rem;

	if (nb == 0)
		return (ft_strdup("0"));
	rem = nb;
	x = (nb < 0);
	while (rem != 0)
	{
		rem = rem / 10;
		x++;
	}
	new = ft_strnew(x);
	if (nb < 0)
		new[0] = '-';
	while (x > 0 && new[x - 1] != '-')
	{
		new[--x] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	return (new);
}

char	*ft_itoa_ull(unsigned long long int nb, int base)
{
	char					*new;
	int						x;
	unsigned long long int	rem;

	x = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	rem = nb;
	while (rem > 0)
	{
		rem = rem / base;
		x++;
	}
	new = ft_strnew(x);
	while (x > 0)
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
