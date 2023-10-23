/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:56:18 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/23 19:24:35 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../stack/stack.h"
#include "../libft/libft.h"

static void	*write_error(char *error_message)
{
	ft_putstr_fd(error_message, 1);
	return (NULL);
}

static int	check_uniq(t_stack_item *start)
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

static t_stack_item	*create_with_checks(char *str)
{
	int				temp;
	t_stack_item	*start;

	temp = ft_atoi(str);
	if (!temp)
		return (write_error("invalid input: not all numbers"));
	start = create_stack_item(temp, 0);
	if (!start)
		return (write_error("error: malloc null'd out"));
	return (start);
}

t_stack_item	*arg_parse(int argc, char *argv[])
{
	t_stack_item	*start;
	t_stack_item	*curr;
	int				i;

	i = 1;
	if (argc < 2)
		return (write_error("invalid input: not enough arguments"));
	start = create_with_checks(argv[i]);
	curr = start;
	if (!curr)
		return (NULL);
	i++;
	while (i < argc)
	{
		curr->next = create_with_checks(argv[i]);
		if (!curr->next)
			return ((t_stack_item *)clear_stack(&start));
		curr->next->prev = curr;
		curr = curr->next;
		i++;
	}
	if (!check_uniq(start))
		return (write_error("invalid input: duplicate numbers"));
	return (start);
}
