/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/01/31 15:04:09 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t nb, int base)
{
	char	*new;
	int		i;
	int		x;
	int		rem;
	int		neg;

	neg = 1;
	i = nb;
	x = 0;
	if (nb < 10 && base == 10)
		neg = -1;
	while (i > 0)
	{
		i = i / base;
		x++;
	}
	new = ft_strnew(x);
	if (!new)
		return (NULL);
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
