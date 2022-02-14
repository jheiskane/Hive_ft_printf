/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diouxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:28:50 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/14 18:52:40 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ox_s(t_printf *tab, char f)
{
	if (f == 'x')
		tab->b_written += write(1, "0x", 2);
	else if (f == 'X')
		tab->b_written += write(1, "0X", 2);
}

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

void	print_di(t_printf *tab)
{
	char	*s;
	char	*tmp;

	s = ft_itoa_base(special_cases_di(tab), 10);
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
	while (*s && !tab->p_not)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		s = align_di(tab, tab->width, ' ', s);
	if (*tmp && *tmp != '0')
		free (tmp);
}

void	print_o(t_printf *tab, int base)
{
	char	*s;
	char	*tmp;

	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), base);
	else
		s = ft_itoa_base(special_cases_uox(tab), base);
	tmp = s;
	if (!tab->preci && *s == '0' && tab->dot && !tab->hash)
		tab->p_not = 1;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->p_not;
	if (tab->hash && tab->preci < 1 && *s != '0')
		tab->preci = 1;
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash && tab->zero)
			align_di(tab, tab->width, '0', s);
		else
			align_di(tab, tab->width, ' ', s);
	}
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	while (*s && !tab->p_not)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	if (*tmp && *tmp != '0')
		free (tmp);
}

void	print_xx(t_printf *tab, char f, int base)
{
	char	*s;
	char	*tmp;

	tab->error = 0;
	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), base);
	else
		s = ft_itoa_base(special_cases_uox(tab), base);
	tmp = s;
	if (!tab->preci && *s == '0' && tab->dot)
		tab->p_not = 1;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->p_not;
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
	{
		if (tab->hash)
		{
			if (*s != '0' && tab->zero && !tab->dot)
				print_ox_s(tab, f);
			align_di(tab, tab->width - 2, ' ', s);
			if (*s != '0' && !tab->zero)
				print_ox_s(tab, f);
		}
		else
			align_di(tab, tab->width, ' ', s);
	}
	else
	{
		if (tab->hash && *s != '0')
			print_ox_s(tab, f);
	}
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	while (*s && !tab->p_not)
	{
		if (f == 'X' && *s != '0')
			*s = (char)ft_toupper(*s);
		tab->b_written += write(1, &*s++, 1);
	}
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width - (2 * tab->hash), ' ', s);
	if (*tmp && *tmp != '0')
		free (tmp);
}

void print_u(t_printf *tab)
{
	char	*s;
	char	*tmp;

	if (tab->ll || tab->l)
		s = ft_itoa_ull(special_cases_uox(tab), 10);
	else
		s = ft_itoa_base(special_cases_uox(tab), 10);
	if (!tab->preci && *s == '0' && tab->dot)
		tab->p_not = 1;
	tmp = s;
	tab->width -= ft_strlen(s);
	tab->preci -= ft_strlen(s);
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		align_di(tab, tab->width, ' ', s);
	if (tab->preci > 0)
		align_di(tab, tab->preci, '0', s);
	if (*s == '-')
		++(*s);
	while (*s && !tab->p_not)
		tab->b_written += write(1, &*s++, 1);
	if (tab->width > 0 && tab->dash)
		align_di(tab, tab->width, ' ', s);
	if (*tmp && *tmp != '0')
		free (tmp);
}
