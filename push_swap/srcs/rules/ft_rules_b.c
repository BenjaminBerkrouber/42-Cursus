/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:23:12 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 22:23:51 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_sb(t_stack *stack)
{
	int	top;
	int	second;

	if (!stack || stack->size < 2)
		return ;
	top = ft_pop(stack);
	second = ft_pop(stack);
	ft_push(stack, top);
	ft_push(stack, second);
	ft_putstr_fd("sb\n", 1);
}

int	ft_pb(t_stack *b, t_stack *a)
{
	int	topb;

	if (!a || a->size == 0)
		return (0);
	topb = ft_pop(a);
	ft_push(b, topb);
	ft_putstr_fd("pb\n", 1);
	return (1);
}

void	ft_rb(t_stack *b)
{
	int		tmp;
	t_stack	*tmp_stack;

	if (!b || b->size <= 1)
		return ;
	tmp = ft_pop(b);
	tmp_stack = init_stack();
	while (b->size > 0)
		ft_push(tmp_stack, ft_pop(b));
	ft_push(b, tmp);
	while (tmp_stack->size > 0)
		ft_push(b, ft_pop(tmp_stack));
	free (tmp_stack);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_stack *b)
{
	t_node	*last;
	t_node	*second_last;

	if (!b || b->size <= 1)
		return ;
	last = b->top;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = b->top;
	b->top = last;
	ft_putstr_fd("rrb\n", 1);
}
