/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:28:50 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/04 16:48:19 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_di(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (i + neg);
}

void	write_n_pad(t_printf *tab, char *s)
{
	while (*s && !tab->p_not)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
}

void	print_di(t_printf *tab)
{
	char	*s;
	char	*tmp;

	s = ft_itoa_ll(special_cases_di(tab));
	if (!s)
		exit(-1);
	tmp = s;
	if (!tab->preci && *s == '0' && tab->dot)
		tab->p_not = 1;
	tab->width -= ft_strlen(s) + ((tab->sign && *s != '-') \
	|| tab->space) - tab->p_not;
	tab->preci -= ft_strlen_di(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		s = align_di(tab, tab->width, ' ', s);
	else if (tab->sign && *s != '-' && !tab->dash)
		tab->b_written += write(1, "+", 1);
	else if (tab->space && *s != '-' && !tab->dash)
		tab->b_written += write(1, " ", 1);
	if (tab->preci > 0)
		s = align_di(tab, tab->preci, '0', s);
	write_n_pad(tab, &*s);
	free(tmp);
}

void	print_o(t_printf *tab, int base)
{
	char	*s;
	char	*tmp;

	s = ft_itoa_ull(special_cases_uox(tab), base);
	tmp = s;
	if (!s)
		exit(-1);
	if (!tab->preci && *s == '0' && tab->dot && !tab->hash)
		tab->p_not = 1;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->p_not;
	if (tab->hash && tab->preci < 1 && *s != '0')
		tab->preci = 1;
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	write_n_pad(tab, &*s);
	free (tmp);
}

void	print_u(t_printf *tab)
{
	char	*s;
	char	*tmp;

	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), 10);
	else
		s = ft_itoa_base(special_cases_uox(tab), 10);
	if (!s)
		exit(-1);
	tmp = s;
	if (!tab->preci && *s == '0' && tab->dot && !tab->hash)
		tab->p_not = 1;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->p_not;
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align_di(tab, tab->width, ' ', s);
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	if (*s == '-')
		++(*s);
	write_n_pad(tab, &*s);
	free (tmp);
}
