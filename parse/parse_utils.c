/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:26:12 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/01 18:39:43 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	*write_error(char *error_message)
{
	error_message = "Error\n";
	ft_putstr_fd(error_message, 1);
	return (NULL);
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

char	**get_all_args(int argc, char *argv[])
{
	int		i;
	char	*result;
	char	*temp1;
	char	*temp2;
	char	**temp3;

	i = 1;
	result = ft_calloc(1, sizeof(char));
	while (i < argc)
	{
		temp1 = ft_strjoin(argv[i], " ");
		temp2 = ft_strjoin(result, temp1);
		free(temp1);
		free(result);
		result = temp2;
		i++;
	}
	temp3 = ft_split(result, ' ');
	free(result);
	return (temp3);
}
