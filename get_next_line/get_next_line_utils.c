/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:08:24 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/06 05:15:26 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	char	*start;

	if (!s)
		return (0);
	start = s;
	while (*s)
		s++;
	return (s - start);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strjoin_free(char *residual, char *buff)
{
	char	*str;
	char	*str_start;
	char	*residual_start;

	if (!residual)
	{
		residual = (char *)malloc(1 * sizeof(char));
		residual[0] = '\0';
	}
	if (!residual || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(residual) + ft_strlen(buff) + 1));
	if (str == NULL)
		return (NULL);
	str_start = str;
	residual_start = residual;
	while (*residual)
		*str++ = *residual++;
	while (*buff)
		*str++ = *buff++;
	*str = '\0';
	free(residual_start);
	return (str_start);
}

/*
** Extracts a line from the given string up to a newline character
** or to the end of the string if no newline is found.
**
** @param  source   The string from which the line is extracted.
** @return            The extracted line or NULL if the string is empty.
*/
char	*extract_line(char *source)
{
	char	*cursor;
	char	*line;
	char	*line_start;

	if (!*source)
		return (NULL);
	cursor = source;
	while (*cursor && *cursor != '\n')
		cursor++;
	line = malloc(sizeof(char) * (cursor - source + 2));
	if (!line)
		return (NULL);
	line_start = line;
	while (*source && *source != '\n')
		*line++ = *source++;
	if (*source == '\n')
		*line++ = *source;
	*line = '\0';
	return (line_start);
}

/*
** Creates a new string after the newline character found in 'residual',
** effectively removing the extracted line from the original string.
**
** @param  source   The original string containing the extracted line.
** @return            A new string that starts after the newline character
**                    or NULL if no newline is found.
*/
char	*new_residual(char *source)
{
	char	*cursor;
	char	*new_str;
	char	*new_str_start;

	cursor = source;
	while (*cursor && *cursor != '\n')
		cursor++;
	if (!*cursor)
	{
		free(source);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(cursor) + 1));
	if (!new_str)
		return (NULL);
	new_str_start = new_str;
	cursor++;
	while (*cursor)
		*new_str++ = *cursor++;
	*new_str = '\0';
	free(source);
	return (new_str_start);
}
