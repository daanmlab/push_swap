/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/01 18:32:53 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	push(t_stack_item **src, t_stack_item **dest)
{
	t_stack_item	*temp;

	if (!(*src))
		return ;
	if (!(*dest))
	{
		temp = (*src)->next;
		*dest = *src;
		(*src)->next->prev = NULL;
		(*dest)->next = NULL;
		*src = temp;
		return ;
	}
	temp = (*src)->next;
	(*dest)->prev = *src;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	if (*src)
		(*src)->prev = NULL;
}

void	pa(t_stack_item **stack_a, t_stack_item **stack_b)
{
	write(1, "pa\n", 3);
	push(stack_b, stack_a);
}

void	pb(t_stack_item **stack_a, t_stack_item **stack_b)
{
	write(1, "pb\n", 3);
	push(stack_a, stack_b);
}
