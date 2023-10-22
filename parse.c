/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:56:18 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 18:16:04 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	*write_error(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	return (NULL);
}

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

void	clear_stack(t_stack_item **stack)
{
	t_stack_item	*temp;

	if (!(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	check_uniq(t_stack_item *start)
{
	t_stack_item	*curr;
	t_stack_item	*curr1;

	curr = start;
	while (curr)
	{
		curr1 = curr->prev;
		while (curr1)
		{
			if (curr->content == curr1->content)
				return (0);
			curr1 = curr1->prev;
		}
		curr = curr->next;
	}
	return (1);
}

t_stack_item	*arg_parse(int argc, char *argv[])
{
	t_stack_item	*start;
	t_stack_item	*curr;
	int				temp;
	int				i;

	i = 1;
	if (argc < 2)
		return (write_error("invalid input: not enough arguments"));
	temp = ft_atoi(argv[i]);
	if (!temp)
		return (write_error("invalid input: not all numbers"));
	start = create_stack_item(temp, i - 1);
	if (!start)
		return (write_error("error: malloc null'd out"));
	curr = start;
	i++;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (!temp)
			return (write_error("invalid input: not all numbers"));
		curr->next = create_stack_item(temp, 0);
		if (!curr->next)
		{
			clear_stack(&start);
			return (write_error("error: malloc null'd out"));
		}
		curr->next->prev = curr;
		curr = curr->next;
		i++;
	}
	if (!check_uniq(start))
		return (write_error("invalid input: duplicate numbers"));
	return (start);
}
