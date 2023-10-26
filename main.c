/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:46 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 01:19:21 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main/main.h"
#include "parse/parse.h"
#include "test/test.h"
#include "moves/moves.h"
#include <stdio.h>

t_stack_item *get_smallest_cost(t_stack_item **stack_b)
{
    t_stack_item *curr;
    t_stack_item *min_cost_node;

    curr = (*stack_b);
    min_cost_node = (*stack_b);
    while (curr)
    {
        if (curr->cost < min_cost_node->cost)
            min_cost_node = curr;
        curr = curr->next;
    }
    return (min_cost_node);
}

void move_up_a(t_stack_item *node, t_stack_item **stack_a)
{
    while (node->prev)
    {
        if(node->go_up)
            ra(stack_a);
        else
            rra(stack_a);
    }
}
void move_up_b(t_stack_item *node, t_stack_item **stack_b)
{
    while (node->prev)
    {
        if(node->go_up)
            rb(stack_b);
        else
            rrb(stack_b);
    }
}

void go(t_stack_item **stack_a, t_stack_item **stack_b)
{
    t_stack_item *curr;
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
	while (curr)
	{
		if (curr->content < min->content)
			min = curr;
		curr = curr->next;
	}
    get_moves_to_top_and_set_go_up(min);
    move_up_a(min, stack_a);
    
}


int	main(int argc, char *argv[])
{
	t_stack_item	*start_a;
	t_stack_item	*start_b;
	t_stack_item	**stack_a;
	t_stack_item	**stack_b;


	start_a = arg_parse(argc, argv);
	start_b = NULL;
	if (!start_a)
		return (0);
	stack_a = &start_a;
	stack_b = &start_b;
	prep_b(stack_a, stack_b);
	prep_a(stack_a, stack_b);
    go(stack_a, stack_b);

	return (0);
}
