/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:59:40 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 16:05:34 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "stack.h"

t_stack_item	*create_stack_item(int content)
{
	t_stack_item	*ret;

	ret = (t_stack_item *)malloc(sizeof(t_stack_item));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->cost = 0;
	ret->go_up = 0;
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

t_stack_item	*add_to_stack(int content, t_stack_item *node)
{
	if (!node)
		return (create_stack_item(content));
	node->next = create_stack_item(content);
	node->next->prev = node;
	return (node->next);
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
