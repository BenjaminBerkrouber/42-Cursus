/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:41:36 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:49:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_padding(t_stack *a)
{
	return (a->size / 4);
}

int	stack_is_sort(t_stack *stack)
{
	t_node	*current;

	if (!stack || !(stack->top))
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	start_sort(t_stack *a, t_stack *b)
{
	if (stack_is_sort(a))
		return ;
	else if (a->size == 2)
		ft_sa(a);
	else if (a->size == 3)
		start_burt_sort(a);
	else if (a->size == 4)
		start_small_sort(a, b);
	else if (a->size == 5)
		start_medium_sort(a, b);
	else
	{
		start_butterfly(a, b, 46);
		finish_butterfly(a, b);
	}
}
