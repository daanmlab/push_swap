/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 22:01:55 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_item	*swap_a(t_stack_item *stack_a)
{
	t_stack_item	*temp;

	ft_putstr_fd("SA\n", 1);
	if (!stack_a || !stack_a->next)
		return (stack_a);
	temp = stack_a->next;
	if (stack_a->next->next)
	{
		stack_a->next->next->prev = stack_a;
		stack_a->next = stack_a->next->next;
	}
	else
		stack_a->next = NULL;
	stack_a->prev = temp;
	temp->next = stack_a;
	temp->prev = NULL;
	return (temp);
}
