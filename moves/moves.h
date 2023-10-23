/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:50:48 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/24 00:53:41 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MOVES_H
# define MOVES_H
# include "../libft/libft.h"
# include "../stack/stack.h"
# include <unistd.h>

void	push(t_stack_item **src, t_stack_item **dest);
void		swap_a(t_stack_item **stack_a);
void		swap_b(t_stack_item **stack_b);
void		swap_both(t_stack_item **a, t_stack_item **b);
void	rotate(t_stack_item **stack);
void	reverse_rotate(t_stack_item **stack);
#endif