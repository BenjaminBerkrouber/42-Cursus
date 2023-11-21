/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:48:39 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/03 22:06:11 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	tot_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tot_size = nmemb * size;
	res = malloc(tot_size);
	if (!res)
		return (NULL);
	ft_bzero(res, tot_size);
	return (res);
}
