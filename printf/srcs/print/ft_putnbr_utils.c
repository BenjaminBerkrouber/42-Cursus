/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:46:00 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:47:05 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_numlen_base(unsigned int n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

size_t	ft_numlen_unsigned(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

size_t	ft_numlen_base_signed(int nbr, int base)
{
	size_t			len;
	unsigned int	unbr;

	len = 0;
	if (nbr < 0)
	{
		len = 1;
		unbr = -nbr;
	}
	else
		unbr = nbr;
	if (unbr == 0)
		len += 1;
	while (unbr != 0)
	{
		len++;
		unbr /= base;
	}
	return (len);
}

int	base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j])
		{
			if (base[i + j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
