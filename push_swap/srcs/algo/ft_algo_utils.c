/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:41:36 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:49:10 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	count_ra(t_stack *a, int padding)
{
	int		ra_count;
	t_node	*current;

	ra_count = 0;
	current = a->top;
	while (current && current->value <= padding)
	{
		ra_count++;
		current = current->next;
	}
	return (ra_count);
}

int	count_rra(t_stack *a, int padding)
{
	int		rra_count;
	t_node	*current;
	int		i;

	rra_count = 0;
	current = a->top;
	i = 0;
	while (i < a->size)
	{
		if (current->value > padding)
		{
			rra_count = i;
			break ;
		}
		if (current->next == NULL)
			current = a->top;
		else
			current = current->next;
		i++;
	}
	return (rra_count);
}

int	is_rra(t_stack *a, int padding)
{
	int	ra_count;
	int	rra_count;

	ra_count = count_ra(a, padding);
	rra_count = count_rra(a, padding);
	return (rra_count < ra_count);
}
