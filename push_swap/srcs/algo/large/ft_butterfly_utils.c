/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:45:34 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:48:13 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_index_of_value(t_stack *stack, int value)
{
	int		index;
	t_node	*current;

	current = stack->top;
	index = 0;
	while (current && current->value != value)
	{
		current = current->next;
		index++;
	}
	if (!current)
		return (-1);
	return (index);
}

void	print_stack(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = a->top;
	printf("Stack A: ");
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\nStack B: ");
	if (!b)
		return ;
	current = b->top;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	copy_nodes(t_stack *copy, t_stack *original)
{
	t_node	*current;
	t_node	*new_node;
	t_node	*last_node;

	current = original->top;
	last_node = NULL;
	while (current)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->value = current->value;
		new_node->next = NULL;
		if (last_node)
			last_node->next = new_node;
		else
			copy->top = new_node;
		last_node = new_node;
		current = current->next;
	}
}

t_stack	*ft_copy_stack(t_stack *original)
{
	t_stack	*copy;

	copy = init_stack();
	if (!copy)
		return (NULL);
	copy->size = original->size;
	copy_nodes(copy, original);
	return (copy);
}
