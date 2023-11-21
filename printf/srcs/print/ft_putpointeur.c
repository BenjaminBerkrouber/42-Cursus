/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:32:59 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:33:22 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_base(unsigned long long value, char *buffer, int base)
{
	char	*hex_digits;
	char	*ptr;

	hex_digits = "0123456789abcdef";
	ptr = &buffer[30];
	*ptr = '\0';
	if (value == 0)
		*(--ptr) = hex_digits[0];
	else
	{
		while (value != 0)
		{
			*(--ptr) = hex_digits[value % base];
			value /= base;
		}
	}
	return (ptr);
}

size_t	ft_putpointeur_va(va_list *args, char charset)
{
	void				*ptr;
	unsigned long long	ptr_val;
	char				buffer[31];
	char				*ptr_str;

	(void)charset;
	ptr = va_arg(*args, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	ptr_val = (unsigned long long)ptr;
	ptr_str = ft_itoa_base(ptr_val, buffer, 16);
	ft_putstr("0x");
	ft_putstr(ptr_str);
	return (2 + ft_strlen(ptr_str));
}
