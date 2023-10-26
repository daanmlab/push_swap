/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:46:52 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 01:20:46 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_moves_to_top_and_set_go_up(t_stack_item *node)
{
	t_stack_item	*up;
	t_stack_item	*down;
	int				count;

	up = &(*node);
	down = &(*node);
	count = 0;
	while (up && down)
	{
		up = up->prev;
		down = down->next;
		count++;
	}
	if (!up)
	{
		node->go_up = 1;
		count--;
	}
	else
		node->go_up = 0;
	return (count);
}

static int	calc_cost(t_stack_item *node_a, t_stack_item *node_b)
{
	return (get_moves_to_top_and_set_go_up(node_a)
		+ get_moves_to_top_and_set_go_up(node_b));
}

void	calc_all_cost(t_stack_item **stack_b)
{
	t_stack_item	*curr;

	curr = (*stack_b);
	while (curr)
	{
		curr->cost = calc_cost(curr->bff, curr);
		curr = curr->next;
	}
}
