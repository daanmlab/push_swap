/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:59:40 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 22:02:13 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_item	*create_stack_item(int content, unsigned int index)
{
	t_stack_item	*ret;

	ret = (t_stack_item *)malloc(sizeof(t_stack_item));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->index = index;
	ret->prev = NULL;
	ret->next = NULL;
	return (ret);
}

void	*clear_stack(t_stack_item **stack)
{
	t_stack_item	*temp;

	if (!(*stack))
		return (NULL);
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
	return (NULL);
}
