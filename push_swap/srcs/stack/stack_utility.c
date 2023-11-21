/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stact_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:13:00 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:13:02 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	ft_is_in_stack(t_stack *a, int value)
{
	t_node	*current;

	current = a->top;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_clear_stack(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	current = a->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	a->top = NULL;
	a->size = 0;
}

int	*copy_stack_to_array(t_stack *stack, int size)
{
	t_node	*current;
	int		*array;
	int		i;

	current = stack->top;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}
