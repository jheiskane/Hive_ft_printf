/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/20 17:14:47 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(size_t nb, int base)
{
	char			*new;
	int				x;
	size_t			rem;

	x = 0 + (nb == 0);
	rem = nb;
	while (rem > 0)
	{
		rem = rem / base;
		x++;
	}
	new = ft_strnew(x);
	if (!new)
		return (NULL);
	while (x > 0)
	{
		rem = nb % base;
		if (rem > 9)
			new[--x] = rem - 10 + 'a';
		else if (rem < 10)
			new[--x] = rem + '0';
		nb /= base;
	}
	return (new);
}
