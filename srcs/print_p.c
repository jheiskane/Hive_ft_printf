/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:47 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/07 13:21:47 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_printf *tab)
{
	char			*s;
	char			*tmp;

	if (tab->dot && tab->preci == 0)
	{
		tab->b_written += write(1, "0x", 2);
		return ;
	}
	s = ft_itoa_base((unsigned long)va_arg(tab->args, size_t), 16);
	tmp = s;
	tab->width -= ft_strlen(s) + 2;
	tab->preci -= ft_strlen(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	tab->b_written += write(1, "0x", 2);
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	free (tmp);
	va_end(tab->args);
}
