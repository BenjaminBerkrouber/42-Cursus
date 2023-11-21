/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:08:06 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:08:08 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!stack || !new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	ft_pop(t_stack *stack)
{
	int		value;
	t_node	*top_node;

	if (!stack || !stack->top)
		return (-1);
	top_node = stack->top;
	value = top_node->value;
	stack->top = stack->top->next;
	free(top_node);
	stack->size--;
	return (value);
}

static int	extract_number(char **ptr)
{
	int	num;

	if (**ptr == '-' || ft_isdigit(**ptr))
	{
		num = ft_atoi(*ptr);
		while (**ptr == '-' || ft_isdigit(**ptr))
			(*ptr)++;
		return (num);
	}
	return (-1);
}

static void	verify_and_add(t_stack *a, int num)
{
	if (ft_is_in_stack(a, num))
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_stack(a);
		exit(EXIT_FAILURE);
	}
	ft_push(a, num);
}

void	complet_stack(int argc, char **argv, t_stack *a)
{
	char	*ptr;
	int		num;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = init_stack();
	while (i < argc)
	{
		ptr = argv[i++];
		while (*ptr)
		{
			if (*ptr == ' ')
				ptr++;
			else
			{
				num = extract_number(&ptr);
				if (num >= 0)
					verify_and_add(tmp, num);
				else
					break ;
			}
		}
	}
	ft_reverse_stack(tmp, a);
}
