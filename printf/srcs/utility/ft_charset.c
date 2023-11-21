/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:39:56 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/12 23:44:32 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_format_info(t_format *format_info)
{
	format_info->left_align = 0;
	format_info->min_width = 0;
	format_info->zero_padding = 0;
	format_info->force_sign = 0;
	format_info->space_add = 0;
	format_info->force_base = 1;
}

void	read_format_info(const char **str, t_format *format_info)
{
	reset_format_info(format_info);
	while (**str)
	{
		if (**str == '-')
			format_info->left_align = 1;
		else if (**str == '+')
			format_info->force_sign = 1;
		else if (**str == ' ')
			format_info->space_add = 1;
		else if (**str == '0')
			format_info->zero_padding = 1;
		else if (**str == '#')
			format_info->force_base = 1;
		else if (ft_isdigit(**str) && **str != '0')
		{
			format_info->min_width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			break ;
		}
		else
			break ;
		(*str)++;
	}
}

int	is_determiner(char **str, t_dec *charsets, t_format *format_info)
{
	size_t	len;
	int		i;

	read_format_info((const char **)str, format_info);
	i = 0;
	while (charsets[i].charset)
	{
		len = ft_strlen(charsets[i].charset);
		if (ft_strncmp(*str, charsets[i].charset, len) == 0)
		{
			*str += len;
			return (i);
		}
		i++;
	}
	return (-1);
}

t_dec	add_charset(char *charset, size_t (*f)(va_list *, char), char *error)
{
	t_dec	element;

	element.charset = charset;
	element.function = f;
	element.error = error;
	return (element);
}

t_dec	*init_charset(void)
{
	t_dec	*charsets;

	charsets = malloc(sizeof(t_dec) * 10);
	if (!charsets)
		return (NULL);
	charsets[0] = add_charset("c", ft_putchar_va, "error %c");
	charsets[1] = add_charset("s", ft_putstr_va, "error %s");
	charsets[2] = add_charset("p", ft_putpointeur_va, "error %p");
	charsets[3] = add_charset("d", ft_putnbr_base_va, "error %d");
	charsets[4] = add_charset("i", ft_putnbr_base_va, "error %i");
	charsets[5] = add_charset("u", ft_putnbr_base_va, "error %u");
	charsets[6] = add_charset("x", ft_putnbr_base_va, "error %x");
	charsets[7] = add_charset("X", ft_putnbr_base_va, "error %X");
	charsets[8] = add_charset("o", ft_putnbr_base_va, "error %o");
	charsets[9] = add_charset(NULL, NULL, NULL);
	return (charsets);
}
