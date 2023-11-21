/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:53:53 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/18 00:55:03 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	move_small_to_b(t_stack *a, t_stack *b)
{
	int	lowest_index;

	lowest_index = find_index_low_value(a);
	move_to_top(a, lowest_index);
	ft_pb(b, a);
}

void	start_small_sort(t_stack *a, t_stack *b)
{
	move_small_to_b(a, b);
	start_burt_sort(a);
	ft_pa(a, b);
}

void	start_medium_sort(t_stack *a, t_stack *b)
{
	move_lower_to_b(a, b);
	start_burt_sort(a);
	while (b->size > 0)
		ft_pa(a, b);
}
