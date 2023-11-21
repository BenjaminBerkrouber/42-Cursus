/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:21:07 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 22:22:11 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	top;
	int	second;

	if (!stack || stack->size < 2)
		return ;
	top = ft_pop(stack);
	second = ft_pop(stack);
	ft_push(stack, top);
	ft_push(stack, second);
	ft_putstr_fd("sa\n", 1);
}

int	ft_pa(t_stack *a, t_stack *b)
{
	int	topb;

	if (!b || b->size == 0)
		return (0);
	topb = ft_pop(b);
	ft_push(a, topb);
	ft_putstr_fd("pa\n", 1);
	return (1);
}

void	ft_ra(t_stack *a)
{
	int		tmp;
	t_stack	*tmp_stack;

	if (!a || a->size <= 1)
		return ;
	tmp = ft_pop(a);
	tmp_stack = init_stack();
	while (a->size > 0)
		ft_push(tmp_stack, ft_pop(a));
	ft_push(a, tmp);
	while (tmp_stack->size > 0)
		ft_push(a, ft_pop(tmp_stack));
	free (tmp_stack);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rra(t_stack *a)
{
	t_node	*last;
	t_node	*second_last;

	if (!a || a->size <= 1)
		return ;
	last = a->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	ft_putstr_fd("rra\n", 1);
}
