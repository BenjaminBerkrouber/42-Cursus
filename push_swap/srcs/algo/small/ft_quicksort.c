/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:24:41 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 22:26:25 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	ft_partition(int array[], int low, int high)
{
	int	pv_value;
	int	i;
	int	j;

	i = low;
	pv_value = array[high];
	j = low;
	while (j < high)
	{
		if (array[j] < pv_value)
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[high]);
	return (i);
}

void	ft_quicksort_recursion(int array[], int low, int high)
{
	int	pv_index;

	if (low < high)
	{
		pv_index = ft_partition(array, low, high);
		ft_quicksort_recursion(array, low, pv_index - 1);
		ft_quicksort_recursion(array, pv_index + 1, high);
	}
}

void	ft_quicksort(int array[], int lenght)
{
	ft_quicksort_recursion(array, 0, lenght -1);
}
