/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:50:21 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:50:57 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <limits.h>

int	is_duplicate(long *array, long num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int is_valid_char(char c)
{
    return (ft_isdigit(c) || c == ' ' || c == '-');
}

//x-xxx
//gere " ", "--1", "overflow" " || -2-2", "5 5", 2147483647
int	is_valide_param(char *str)
{
	long	num;
	long	*num_array;
	long	*temp;
	int		num_count;
	int		i;
	int		j;

	i = 0;
	num_array = NULL;
	num_count = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (str[i] == '-' && (!ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
			return (0);
		if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
		{
			if (str[i] == '-')
				j = i + 1;
			else
				j = i;
			while (ft_isdigit(str[j]))
				j++;
			num = ft_atol(&(str[i]));
			if (num > MAX_INT || num < MIN_INT
				|| is_duplicate(num_array, num, num_count))
			{
				free(num_array);
				return (0);
			}
			temp = realloc(num_array, (num_count + 1) * sizeof(long));
			if (!temp)
			{
				free(num_array);
				return (0);
			}
			num_array = temp;
			num_array[num_count++] = num;
			i = j;
		}
		else
			i++;
	}
	free(num_array);
	return (1);
}

int	is_valide_parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valide_param(argv[i]))
			return (0);
		i++;
	}
	return (1);
}