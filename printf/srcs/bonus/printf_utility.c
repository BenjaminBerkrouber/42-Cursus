/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:20:40 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 11:22:01 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_va(va_list *args, t_dec *charsets, char specifier)
{
	size_t	char_count;
	size_t	i;

	char_count = 0;
	i = 0;
	while (charsets[i].charset != NULL)
	{
		if (ft_strchr(charsets[i].charset, specifier))
		{
			char_count = charsets[i].function(args, *charsets[i].charset);
			return (char_count);
		}
		i++;
	}
	return (0);
}
