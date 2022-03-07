/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:13:26 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/07 12:21:14 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_f(t_printf *tab)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	s = ft_itoa_float(tab, special_cases_f(tab));
	tmp = s;
	tab->width -= ft_strlen(s) + (tab->sign || tab->space);
	if (tab->width > 0 && !tab->dash)
		s = align_f(tab, tab->width, ' ', s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		s = align_f(tab, tab->preci, ' ', s);
	free (tmp);
	va_end(tab->args);
}
