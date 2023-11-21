/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:45:00 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/15 12:45:35 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	size_t	len;
	long	ln;

	len = 0;
	ln = n;
	if (ln < 0)
	{
		len += ft_putchar('-');
		ln = -ln;
	}
	if (ln >= 10)
		len += ft_putnbr(ln / 10);
	len += ft_putchar((ln % 10) + '0');
	return (len);
}

void	putnbr_min_int(int nbr, char *base, int base_size, int first)
{
	if (first)
		write(1, "-", 1);
	if (nbr <= base_size * -1)
	{
		putnbr_min_int(nbr / base_size, base, base_size, 0);
		putnbr_min_int(nbr % base_size, base, base_size, 0);
	}
	else
	{
		write(1, &base[nbr * -1], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	if (base_is_valid(base))
	{
		base_size = ft_strlen(base);
		if (nbr == -2147483648)
			putnbr_min_int(nbr, base, base_size, 1);
		else
		{
			if (nbr < 0)
			{
				write(1, "-", 1);
				nbr *= -1;
			}
			if (nbr >= base_size)
			{
				ft_putnbr_base(nbr / base_size, base);
				ft_putnbr_base(nbr % base_size, base);
			}
			else
				write(1, &base[nbr], 1);
		}
	}
}

void	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
	unsigned int	base_size;

	if (base_is_valid(base))
	{
		base_size = ft_strlen(base);
		if (nbr >= base_size)
		{
			ft_putnbr_base_unsigned(nbr / base_size, base);
			ft_putnbr_base_unsigned(nbr % base_size, base);
		}
		else
			write(1, &base[nbr], 1);
	}
}

size_t	ft_putnbr_base_va(va_list *args, char charset)
{
	unsigned int	n;
	size_t			len;

	n = va_arg(*args, unsigned int);
	if (charset == 'd' || charset == 'i')
		ft_putnbr_base(n, "0123456789");
	else if (charset == 'x')
		ft_putnbr_base_unsigned(n, "0123456789abcdef");
	else if (charset == 'X')
		ft_putnbr_base_unsigned(n, "0123456789ABCDEF");
	else if (charset == 'u')
		ft_putnbr_base_unsigned(n, "0123456789");
	else if (charset == 'o')
		ft_putnbr_base(n, "01234567");
	if (charset == 'x' || charset == 'X')
		len = ft_numlen_base(n, 16);
	else if (charset == 'o')
		len = ft_numlen_base(n, 8);
	else if (charset == 'd' || charset == 'i')
		len = ft_numlen_base_signed(n, 10);
	else
		len = ft_numlen_base(n, 10);
	return (len);
}
