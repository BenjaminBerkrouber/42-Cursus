/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:38:49 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/18 03:42:18 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	normaliser_stack(t_stack *stack)
{
	int		*tab;
	t_node	*current;
	int		i;

	tab = copy_stack_to_array(stack, stack->size);
	if (!tab)
		return ;
	ft_quicksort(tab, stack->size);
	current = stack->top;
	while (current)
	{
		i = 0;
		while (current->value != tab[i])
			i++;
		current->value = i;
		current = current->next;
	}
	free(tab);
}

void	ft_reverse_stack(t_stack *tmp, t_stack *a)
{
	while (tmp->top != NULL)
	{
		ft_push(a, ft_pop(tmp));
	}
	free(tmp);
}

int	main(int argc, char **argv)
{
	t_stack	*b;
	t_stack	*a;

	if (argc == 1)
		return (0);
	if (!is_valide_parsing(argc, argv))
		return (0);
	a = init_stack();
	b = init_stack();
	complet_stack(argc, argv, a);
	if (!a)
		return (1);
	normaliser_stack(a);
	start_sort(a, b);
	while (a->top != NULL)
		ft_pop(a);
	free(a);
	free(b);
	return (0);
}
