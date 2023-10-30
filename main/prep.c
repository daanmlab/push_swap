/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:39:12 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/30 19:35:01 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../moves/moves.h"
#include "main.h"

static int	get_avg(t_stack_item **stack)
{
	t_stack_item	*curr;
	int				sum;
	int				count;

	curr = *stack;
	sum = 0;
	count = 0;
	while (curr)
	{
		sum += curr->content;
		count++;
		curr = curr->next;
	}
	return (sum / count);
}

static void	tiny_sort(t_stack_item **stack_a, int len)
{
	if (len == 2)
		return (sa(stack_a));
	else if (len == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		{
			rra(stack_a);
		}
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
}

/**
 * to push everything except for the biggest five to stack_b
*/
void	prep_b(t_stack_item **stack_a, t_stack_item **stack_b)
{
	int	stack_a_length;

	stack_a_length = get_stack_length(stack_a);
	while (stack_a_length > 3)
	{
		if ((*stack_a)->content < get_avg(stack_a))
		{
			pb(stack_a, stack_b);
			stack_a_length--;
		}
		else
			ra(stack_a);
	}
}

/**
 * to get the smallest node in the stack
*/
static t_stack_item	*get_min(t_stack_item **stack)
{
	t_stack_item	*curr;
	t_stack_item	*selected;

	curr = (*stack);
	selected = curr;
	while (curr)
	{
		if (curr->content < selected->content)
			selected = curr;
		curr = curr->next;
	}
	return (selected);
}

/**
 * to sort stack_a
*/
void	prep_a(t_stack_item **stack_a, t_stack_item **stack_b)
{
	int				stack_a_length;
	int				temp;
	t_stack_item	*selected;

	temp = get_min(stack_a)->content;
	selected = (*stack_b);
	stack_a_length = get_stack_length(stack_a);
	tiny_sort(stack_a, get_stack_length(stack_a));
}
