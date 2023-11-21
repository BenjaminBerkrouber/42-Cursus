/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brut_force.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:56:22 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/18 00:57:37 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	start_burt_sort(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top < middle && middle > bottom && top < bottom)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (top > middle && middle < bottom && bottom > top)
		ft_sa(a);
	else if (top < middle && middle > bottom && top > bottom)
		ft_rra(a);
	else if (top > middle && middle < bottom && top > bottom)
		ft_ra(a);
	else if (top > middle && middle > bottom)
	{
		ft_sa(a);
		ft_rra(a);
	}
}
