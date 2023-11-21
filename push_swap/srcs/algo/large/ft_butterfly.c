/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:41:36 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:49:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	start_butterfly(t_stack *a, t_stack *b, int padding)
{
	int	i;
	int	value;
	int	size;
	int	spad;

	spad = padding;
	i = 0;
	size = a->size;
	while (i < size)
	{
		while (i <= padding && i < size)
		{
			value = a->top->value;
			if (value <= padding)
			{
				i += ft_pb(b, a);
				if (!(value <= padding - (spad / 2)))
					ft_rb(b);
			}
			else if (is_rra(a, padding))
				ft_rra(a);
			else
				ft_ra(a);
		}
		padding += spad;
	}
}

void	finish_butterfly(t_stack *a, t_stack *b)
{
	int	size;
	int	index;
	int	i;
	int	target;

	i = 0;
	size = b->size;
	while (i < size)
	{
		target = (b->size - 1);
		index = find_index_of_value(b, target);
		if (index <= (b->size - index))
		{
			while (b->top->value != target)
				ft_rb(b);
		}
		else
			while (b->top->value != target)
				ft_rrb(b);
		i += ft_pa(a, b);
	}
}
