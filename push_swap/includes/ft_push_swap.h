/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:15:55 by bberkrou          #+#    #+#             */
/*   Updated: 2023/11/10 23:23:24 by bberkrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "ft_parsing.h"
# include "ft_algo.h"
# include "ft_rules.h"
# include "ft_stack.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

void	print_stack(t_stack *a, t_stack *b);
void	ft_reverse_stack(t_stack *tmp, t_stack *a);

#endif
