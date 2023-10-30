/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:24 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 15:16:23 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	reverse_rotate(t_stack_item **stack)
{
	t_stack_item	*last;
	t_stack_item	*first;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = (*stack);
	first = (*stack);
	while (last->next)
		last = last->next;
	if (last == first)
		return ;
	first->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	*stack = last;
}

void	rrb(t_stack_item **stack_b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(stack_b);
}

void	rra(t_stack_item **stack_a)
{
	write(1, "rra\n", 4);
	reverse_rotate(stack_a);
}

void	rrr(t_stack_item **stack_a, t_stack_item **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
