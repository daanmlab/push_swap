/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:50:48 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/01 18:34:07 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H
# include "../libft/libft.h"
# include "../stack/stack.h"
# include <unistd.h>

void	pa(t_stack_item **stack_a, t_stack_item **stack_b);
void	pb(t_stack_item **stack_a, t_stack_item **stack_b);
void	rrb(t_stack_item **stack_b);
void	rra(t_stack_item **stack_a);
void	rrr(t_stack_item **stack_a, t_stack_item **stack_b);
void	rb(t_stack_item **stack_b);
void	ra(t_stack_item **stack_a);
void	rr(t_stack_item **stack_a, t_stack_item **stack_b);
void	sa(t_stack_item **stack_a);
void	sb(t_stack_item **stack_b);
void	ss(t_stack_item **stack_a, t_stack_item **stack_b);

// for checker
void	swap(t_stack_item **stack);
void	push(t_stack_item **src, t_stack_item **dest);
void	rotate(t_stack_item **stack);
void	reverse_rotate(t_stack_item **stack);

#endif