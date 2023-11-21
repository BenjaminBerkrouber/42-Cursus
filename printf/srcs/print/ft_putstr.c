/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:38:19 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:47:26 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

size_t	ft_putstr_va(va_list *args, char charset)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
		return (ft_putstr("(null)"));
	(void)charset;
	ft_putstr(str);
	return (ft_strlen(str));
}

size_t	ft_putchar_va(va_list *args, char charset)
{
	char	c;

	(void)charset;
	c = (char)va_arg(*args, int);
	ft_putchar(c);
	return (1);
}
