/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:16:34 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/11 14:55:37 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*align_di(t_printf *tab, int len, char c, char *s)
{
	int	i;

	i = 0;
	if ((tab->zero && !tab->dot) || c == '0')
	{
		if (*s == '-')
			tab->b_written += write(1, &*s++, 1);
		else if (tab->sign)
			tab->b_written += write(1, "+", 1);
		else if (tab->space)
			tab->b_written += write(1, " ", 1);
	}
	if (tab->zero && !tab->dot && !tab->dash)
		c = '0';
	while (len > i)
	{
		write(1, &c, 1);
		i++;
	}
	if (c == ' ' && *s == '-')
		tab->b_written += write(1, &*s++, 1);
	tab->b_written += len;
	return (s);
}
/*
If printing zeros before the number, add '-' before the zeros
*/

char	*align_f(t_printf *tab, int len, char c, char *s)
{
	int	i;

	i = 0;
	if (tab->zero)
	{
		if (*s == '-')
			tab->b_written += write(1, &*s++, 1);
		else if (tab->sign)
		{
			tab->b_written += write(1, "+", 1);
			len--;
		}
		else if (tab->space || *s == '0')
			tab->b_written += write(1, " ", 1);
	}
	if (tab->zero && !tab->dash)
		c = '0';
	while (len > i++)
		write(1, &c, 1);
	if (!tab->zero && *s == '-')
		tab->b_written += write(1, &*s++, 1);
	tab->b_written += len;
	return (s);
}

void	align(t_printf *tab, int len, char c)
{
	int	i;

	i = 0;
	if (tab->zero && !tab->dash)
		c = '0';
	while (len > i)
	{
		write(1, &c, 1);
		i++;
	}
	tab->b_written += len;
}
