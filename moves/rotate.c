/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/01 18:33:05 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	rotate(t_stack_item **stack)
{
	t_stack_item	*last;
	t_stack_item	*first;
	t_stack_item	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = (*stack);
	first = (*stack);
	temp = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = last;
	*stack = temp;
}

void	rb(t_stack_item **stack_b)
{
	write(1, "rb\n", 3);
	rotate(stack_b);
}

void	ra(t_stack_item **stack_a)
{
	write(1, "ra\n", 3);
	rotate(stack_a);
}

void	rr(t_stack_item **stack_a, t_stack_item **stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}
