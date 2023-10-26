/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:59:40 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 01:19:32 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// unsigned int		index;
// int					content;
// int					cost;
// struct s_stack_item	*bff;
// struct s_stack_item	*prev;
// struct s_stack_item	*next;

t_stack_item	*create_stack_item(int content, unsigned int index)
{
	t_stack_item	*ret;

	ret = (t_stack_item *)malloc(sizeof(t_stack_item));
	if (!ret)
		return (NULL);
	ret->index = index;
	ret->content = content;
	ret->cost = 0;
	ret->bff = NULL;
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

int	get_stack_length(t_stack_item **stack)
{
	t_stack_item	*curr;
	int				count;

	curr = *stack;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
