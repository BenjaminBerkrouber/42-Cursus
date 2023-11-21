/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:00:32 by bberkrou          #+#    #+#             */
/*   Updated: 2023/10/31 11:17:26 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_substring(const char *str, const char *to_find
								, size_t start, size_t len)
{
	size_t	j ;

	j = 0;
	while (str[start + j] && str[start + j] == to_find[j] && (start + j) < len)
	{
		if (to_find[j + 1] == 0)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	str_len;
	size_t	find_len;

	if ((str == NULL || to_find == NULL) && len == 0)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	find_len = ft_strlen(to_find);
	if (find_len == 0)
		return ((char *)str);
	while (str[i] && i < len)
	{
		if (i + find_len > len)
			break ;
		if (match_substring(str, to_find, i, len))
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
