/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:12:37 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/01 09:17:28 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(const char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (count);
}

static void	free_allocated_strings(char **strings, int i)
{
	while (i >= 0)
		free(strings[i--]);
	free(strings);
}

static char	*allocate_and_fill(const char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_split_aux(const char **str, char **strings, char sep, int *i)
{
	int		len;

	len = 0;
	while (**str && !(**str == sep))
	{
		(*str)++;
		len++;
	}
	strings[*i] = allocate_and_fill(*str - len, len);
	if (!strings[*i])
		return (NULL);
	(*i)++;
	return (strings);
}

char	**ft_split(const char *str, char sep)
{
	char	**strings;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, sep) + 1));
	if (!strings)
		return (NULL);
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
		{
			strings = ft_split_aux(&str, strings, sep, &i);
			if (!strings)
				return (free_allocated_strings(strings, i), NULL);
		}
		while (*str && !(*str == sep))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
