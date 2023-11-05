/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:17:43 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 16:03:39 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_main.h"
#include "main/main.h"
#include "moves/moves.h"
#include "parse/parse.h"
#include "stack/stack.h"
#include <unistd.h>

void	do_move1(char *move, t_stack_item **stack_a, t_stack_item **stack_b)
{
	if (!ft_strncmp(move, "rb\n", 10))
		rotate(stack_b);
	else if (!ft_strncmp(move, "ra\n", 10))
		rotate(stack_a);
	else if (!ft_strncmp(move, "rr\n", 10))
	{
		rotate(stack_b);
		rotate(stack_a);
	}
	else if (!ft_strncmp(move, "sa\n", 10))
		swap(stack_a);
	else if (!ft_strncmp(move, "sb\n", 10))
		swap(stack_b);
	else if (!ft_strncmp(move, "ss\n", 10))
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	do_move2(char *move, t_stack_item **stack_a, t_stack_item **stack_b)
{
	if (!ft_strncmp(move, "pa\n", 10))
		push(stack_b, stack_a);
	else if (!ft_strncmp(move, "pb\n", 10))
		push(stack_a, stack_b);
	else if (!ft_strncmp(move, "rrb\n", 10))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(move, "rra\n", 10))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(move, "rrr\n", 10))
	{
		reverse_rotate(stack_b);
		reverse_rotate(stack_a);
	}
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

void	do_moves(t_stack_item **stack_a, t_stack_item **stack_b)
{
	char	*curr_line;

	curr_line = get_next_line(0);
	while (curr_line)
	{
		do_move1(curr_line, stack_a, stack_b);
		do_move2(curr_line, stack_a, stack_b);
		curr_line = get_next_line(0);
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
	do_moves(stack_a, stack_b);
	if (is_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack_a);
	free_stack(stack_b);
}
