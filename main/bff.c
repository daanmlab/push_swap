/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:11:06 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 01:20:41 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	find_bff(t_stack_item **stack_a, t_stack_item *og)
{
	t_stack_item	*curr;
	int				temp;

	curr = (*stack_a);
	while (curr->content - og->content < 0)
		curr = curr->next;
	og->bff = curr;
	while (curr)
	{
		temp = curr->content - og->content;
		if (temp > 0 && curr->content < og->bff->content)
			og->bff = curr;
		curr = curr->next;
	}
}

void	find_all_bffs(t_stack_item **stack_a, t_stack_item **stack_b)
{
	t_stack_item	*curr;

	curr = (*stack_b);
	while (curr)
	{
		curr->bff = NULL;
		find_bff(stack_a, curr);
		curr = curr->next;
	}
}
