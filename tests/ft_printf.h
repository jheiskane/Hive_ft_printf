/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:38:39 by ishakuro          #+#    #+#             */
/*   Updated: 2022/02/02 14:49:36 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_printf
{
	va_list	args;
	int		b_written;
	int		width;
	int		preci;
	int		dash;
	int		sign;
	int		zero;
	int		percent;
	int		space;
	int		dot;
	int		h;
	int		L;
	int		l;
	int		hh;
	int		ll;
	int		hash;
	int		error;
	int		ret;
	char 	*conversions;
}			t_printf;

int	ft_printf (const char *str_format, ...);
int	calc_preci(t_printf *tab, const char *str, int i);
size_t	special_cases_di(t_printf *tab);
int	is_dot(t_printf *tab, const char *str, int i);
int	is_percent(t_printf *tab, const char *str, int i);
int	is_space(t_printf *tab, const char *str, int i);
int	is_sign(t_printf *tab, const char *str, int i);
int	is_dash(t_printf *tab, const char *str, int i);
int	is_hash(t_printf *tab, const char *str, int i);
int	is_percent(t_printf *tab, const char *str, int i);
int	is_zero(t_printf *tab, const char *str, int i);
int	is_l(t_printf *tab, const char *str, int i);
int	is_h(t_printf *tab, const char *str, int i);
int	is_L(t_printf *tab, const char *str, int i);
int	is_width(t_printf *tab, const char *str, int i);
int	print_format(t_printf *tab, char f);
void	right_align(t_printf *tab, int len);
void	left_align(t_printf *tab, int len);
void print_char(t_printf *tab);
void print_s(t_printf *tab);
void print_di(t_printf *tab);
char	*ft_itoa_base(long long int nb, int base);
void print_p(t_printf *tab);

#endif
