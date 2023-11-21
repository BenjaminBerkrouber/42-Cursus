/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:00:24 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:55:11 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_format
{
	size_t	min_width;
	int		left_align;
	int		zero_padding;
	int		precision;
	int		force_sign;
	int		space_add;
	int		force_base;
}	t_format;

typedef struct s_dec
{
	char	*charset;
	size_t	(*function)(va_list *, char);
	char	*error;
}	t_dec;

size_t	ft_putchar(char c);
t_dec	*init_charset(void);
void	read_format_info(const char **str, t_format *format_info);
size_t	ft_numlen(int n);
int		ft_printf(const char *format, ...);
size_t	ft_put_va(va_list *args, t_dec *charsets, char specifier);
size_t	ft_putstr(char *s);
size_t	ft_numlen_base(unsigned int n, int base);
int		is_determiner(char **str, t_dec *charsets, t_format *format_info);
size_t	ft_putstr_va(va_list *args, char charset);
size_t	ft_putnbr_base_va(va_list *args, char charset);
size_t	ft_putchar_va(va_list *args, char charset);
size_t	ft_putpointeur_va(va_list *args, char charset);
size_t	ft_numlen_base(unsigned int n, int base);
size_t	ft_numlen_unsigned(unsigned int n);
size_t	ft_numlen_base_signed(int nbr, int base);
int		base_is_valid(char *base);
#endif
