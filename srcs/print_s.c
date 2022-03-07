/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:32:00 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/07 13:44:09 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_printf *tab)
{
	int		len;
	char	*p;

	p = va_arg(tab->args, char *);
	if (!p)
	{
		tab->b_written += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(p);
	if (tab->dot && tab->preci < len)
		tab->width -= tab->preci;
	else
		tab->width -= len;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0 || tab->dot)
		len = tab->preci;
	while (*p && len-- != 0)
		tab->b_written += write(1, &*p++, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}
