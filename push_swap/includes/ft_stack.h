/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:14:47 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/18 03:47:07 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

void	ft_push(t_stack *stack, int value);
int		ft_pop(t_stack *stack);
int		*copy_stack_to_array(t_stack *stack, int size);
void	complet_stack(int argc, char **argv, t_stack *a);
void	ft_clear_stack(t_stack *a);
t_stack	*init_stack(void);
int		ft_is_in_stack(t_stack *a, int value);

#endif
