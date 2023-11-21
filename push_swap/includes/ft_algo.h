/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:23:33 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:24:39 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	start_sort(t_stack *a, t_stack *b);
void	ft_quicksort(int array[], int lenght);
void	start_burt_sort(t_stack *a);
void	start_small_sort(t_stack *a, t_stack *b);
void	start_medium_sort(t_stack *a, t_stack *b);
void	start_butterfly(t_stack *a, t_stack *b, int padding);
void	finish_butterfly(t_stack *a, t_stack *b);

void	move_lower_to_b(t_stack *a, t_stack *b);
int		find_index_low_value(t_stack *a);
void	move_to_top(t_stack *a, int index);

int		find_index_of_value(t_stack *stack, int value);
int		stack_is_sort(t_stack *stack);
int		is_rra(t_stack *a, int padding);
#endif
