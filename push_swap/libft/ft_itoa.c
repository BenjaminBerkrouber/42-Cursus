/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:15:22 by bberkrou          #+#    #+#             */
/*   Updated: 2023/10/30 15:02:31 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;
	long	ld;

	ld = (long)n;
	size = get_size(ld);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = 0;
	if (ld == 0)
		str[0] = '0';
	else if (ld < 0)
	{
		str[0] = '-';
		ld *= -1;
	}
	i = size - 1;
	while (ld > 0)
	{
		str[i--] = (ld % 10) + '0';
		ld /= 10;
	}
	return (str);
}
