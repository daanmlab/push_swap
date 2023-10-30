/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:46 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/30 19:35:25 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/main.h"
#include "moves/moves.h"
#include "parse/parse.h"
#include "stack/stack.h"
#include "test/test.h"
#include <stdio.h>

void	move_up_a(t_stack_item *node, t_stack_item **stack_a)
{
	while (node->prev)
	{
		if (node->go_up)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	move_up_b(t_stack_item *node, t_stack_item **stack_b)
{
	while (node->prev)
	{
		if (node->go_up)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	go(t_stack_item **stack_a, t_stack_item **stack_b)
{
	t_stack_item	*curr;
	t_stack_item	*min;

	while (*stack_b)
	{
		find_all_bffs(stack_a, stack_b);
		calc_all_cost(stack_b);
		curr = get_smallest_cost(stack_b);
		move_up_a(curr->bff, stack_a);
		move_up_b(curr, stack_b);
		pa(stack_a, stack_b);
		curr->bff = NULL;
	}
	curr = (*stack_a);
	min = curr;
	while (curr)
	{
		if (curr->content < min->content)
			min = curr;
		curr = curr->next;
	}
	get_moves_to_top_and_set_go_up(min);
	move_up_a(min, stack_a);
}

void	free_stack(t_stack_item **stack)
{
	t_stack_item	*curr;
	t_stack_item	*temp;

	curr = (*stack);
	temp = NULL;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}

int	main(int argc, char *argv[])
{
	t_stack_item	*start_a;
	t_stack_item	*start_b;
	t_stack_item	**stack_a;
	t_stack_item	**stack_b;

	if (argc < 2)
	{
		return (0);
	}
	start_a = parse(argc, argv);
	if (!start_a)
		return (0);
	start_b = NULL;
	stack_b = &start_b;
	stack_a = &start_a;
	if (is_sorted(stack_a))
		return (0);
	prep_b(stack_a, stack_b);
	prep_a(stack_a, stack_b);
	if ((*stack_b))
		go(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
