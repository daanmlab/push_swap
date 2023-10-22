/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 23:53:49 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	rotate(t_stack_item **stack)
{
    t_stack_item *last;
    t_stack_item *first;
    t_stack_item *temp;
	if (!(*stack) || !((*stack)->next))
        return;
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

void	reverse_rotate(t_stack_item **stack)
{
    t_stack_item *last;
    t_stack_item *first;
	if (!(*stack) || !((*stack)->next))
        return;
    last = (*stack);
    first = (*stack);
    while (last->next)
        last = last->next;
    if(last == first)
        return;
    first->prev = last;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    *stack = last;
}

