/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:53:19 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:54:23 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	print_nonformat_char(const char **format)
{
	ft_putchar(**format);
	(*format)++;
	return (1);
}

int	handle_format(const char **format, va_list *args, t_dec *charsets)
{
	int	char_count;

	(*format)++;
	if (**format == '%')
	{
		ft_putchar('%');
		(*format)++;
		return (1);
	}
	else
	{
		char_count = ft_put_va(args, charsets, **format);
		if (**format)
			(*format)++;
		return (char_count);
	}
}

int	ft_printf(const char *format, ...)
{
	t_dec		*charsets;
	va_list		args;
	int			char_count;

	if (!format)
		return (-1);
	charsets = init_charset();
	if (!charsets)
		return (-1);
	char_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			char_count += handle_format(&format, &args, charsets);
		else
			char_count += print_nonformat_char(&format);
	}
	free(charsets);
	va_end(args);
	return (char_count);
}
