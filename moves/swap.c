/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/24 18:25:03 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	swap(t_stack_item **stack)
{
	t_stack_item	*first;
	t_stack_item	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (first->next->next)
	{
		second->next->prev = first;
		first->next = second->next;
	}
	else
		first->next = NULL;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_stack_item **stack_a)
{
	ft_putstr_fd("sa\n", 1);
	swap(stack_a);
}

void	sb(t_stack_item **stack_b)
{
	ft_putstr_fd("sb\n", 1);
	swap(stack_b);
}

void	ss(t_stack_item **stack_a, t_stack_item **stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap(stack_a);
	swap(stack_b);
}
