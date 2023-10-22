/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:56:18 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 00:43:12 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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

void clear_stack(t_stack_item **stack)
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


t_stack_item	*arg_parse(int argc, char *argv[])
{
	t_stack_item 	*start;
	t_stack_item 	*curr;
	int 			temp;
	int 			i;
	
	i = 1;
	if(argc < 2)
		return NULL;
	temp = ft_atoi(argv[i]);
	if (!temp)
		return NULL;
	start = create_stack_item(temp, i - 1);
	if (!start)
		return NULL;
	curr = start;
	i++;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (!temp)
			return NULL;
		curr->next = create_stack_item(temp, i - 1);
		if (!curr->next)
		{
			clear_stack(&start);
			return NULL;
		}
		curr->next->prev = curr;
		curr = curr->next;
		i++;
	}
	return start;
}



#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stack_item *test;
	
	test = arg_parse(argc, argv);
	print_stack(test);
}