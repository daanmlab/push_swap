/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:18:25 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/23 19:08:26 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse.h"
#include "../stack/stack.h"
#include "../libft/libft.h"

static void	find_and_lower_index(t_stack_item *start, int min)
{
	t_stack_item	*curr;

	curr = start;
	while (curr)
	{
		if (curr->content == min)
			curr->index--;
		curr = curr->next;
	}
}

static int	get_min_and_incr_index(t_stack_item *start, unsigned int index,
		int min)
{
	t_stack_item	*curr;

	curr = start;
	while (curr)
	{
		if (curr->index == index)
		{
			curr->index = index + 1;
			if (curr->content < min)
				min = curr->content;
		}
		curr = curr->next;
	}
	return (min);
}

void	sort(t_stack_item *start)
{
	t_stack_item	*curr;
	t_stack_item	*curr1;
	unsigned int	index;
	int				min;

	index = 0;
	curr = start;
	while (curr)
	{
		curr1 = start;
		while (curr1->index != index)
			curr1 = curr1->next;
		min = get_min_and_incr_index(start, index, curr1->content);
		find_and_lower_index(start, min);
		index++;
		curr = curr->next;
	}
}
