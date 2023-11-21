/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:51:41 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/06 05:13:07 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Reads characters from file descriptor into the buffer until newline
** is found or the end of file is reached. Joins the buffer content
** to the static resover string from previous calls.
**
** @param  fd         The file descriptor to read from.
** @param  residual   The static string containing resovers from previous reads.
** @return            The updated string containing read characters including
**                    the newline character if it was found.
*/
char	*read_to_residual(int fd, char *residual)
{
	char	*buff;
	char	*new_residual;
	int		rd_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	new_residual = residual;
	while (!ft_strchr(new_residual, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		new_residual = ft_strjoin_free(new_residual, buff);
	}
	free(buff);
	return (new_residual);
}

/*
** Retrieves the next line from the file descriptor specified.
** A line is defined as a sequence of characters followed by a '\n' or EOF.
**
** @param  fd   The file descriptor to read from.
** @return      A string containing the next line from the file descriptor.
*/
char	*get_next_line(int fd)
{
	char		*current_line;
	static char	*residual;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	residual = read_to_residual(fd, residual);
	if (!residual)
		return (NULL);
	current_line = extract_line(residual);
	residual = new_residual(residual);
	return (current_line);
}
