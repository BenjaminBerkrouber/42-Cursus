/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:53:53 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/18 00:55:03 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	move_to_top(t_stack *a, int index)
{
	if (index < a->size / 2)
		while (index--)
			ft_ra(a);
	else
	{
		index = a->size - index;
		while (index--)
			ft_rra(a);
	}
}

int	find_index_low_value(t_stack *a)
{
	int		lowest_value;
	int		lowest_index;
	int		index;
	t_node	*current;

	if (a == NULL || a->top == NULL)
		return (-1);
	current = a->top;
	lowest_value = current->value;
	lowest_index = 0;
	index = 0;
	while (current != NULL)
	{
		if (current->value < lowest_value)
		{
			lowest_value = current->value;
			lowest_index = index;
		}
		current = current->next;
		index++;
	}
	return (lowest_index);
}

void	move_lower_to_b(t_stack *a, t_stack *b)
{
	int	lowest_index;

	lowest_index = find_index_low_value(a);
	move_to_top(a, lowest_index);
	ft_pb(b, a);
	lowest_index = find_index_low_value(a);
	move_to_top(a, lowest_index);
	ft_pb(b, a);
}
