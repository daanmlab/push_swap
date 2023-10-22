/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:18:25 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 17:41:47 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		min = curr1->content;
		while (curr1)
		{
			if (curr1->index == index)
			{
				curr1->index = index + 1;
				if (curr1->content < min)
					min = curr1->content;
			}
			curr1 = curr1->next;
		}
		curr1 = start;
		while (curr1)
		{
			if (curr1->content == min)
				curr1->index--;
			curr1 = curr1->next;
		}
		index++;
		curr = curr->next;
	}
}
