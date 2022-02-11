/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:38:39 by ishakuro          #+#    #+#             */
/*   Updated: 2022/02/11 12:48:32 by jheiskan         ###   ########.fr       */
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
	int		p_nothi;
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

long double ft_abs(long double nb);
char	*align_f(t_printf *tab, int len, char c, char *s);
char	*conv_hash(t_printf *tab, char *str, char f);
char	*ft_itoa_ull(unsigned long long int nb, int base);
size_t	special_cases_uox(t_printf *tab);
void	fill_preci_diouxX(t_printf *tab);
///char	*ft_itoa_double(long double nb, int preci);
long double	special_cases_f(t_printf *tab);
void print_f(t_printf *tab);
char	*ft_itoa_float(t_printf *tab, long double nb);
void print_u(t_printf *tab);
void	print_xX(t_printf *tab, char f, int base);
void	print_o(t_printf *tab, int base);
int	ft_printf (const char *str_format, ...);
int	calc_preci(t_printf *tab, const char *str, int i);
ssize_t	special_cases_di(t_printf *tab);
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
void	align(t_printf *tab, int len, char c);
void print_char(t_printf *tab);
void print_s(t_printf *tab);
void print_di(t_printf *tab);
char	*ft_itoa_base(long long int nb, int base);
void print_p(t_printf *tab);
char	*align_di(t_printf *tab, int len, char c, char *s);

#endif
