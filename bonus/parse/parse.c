/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:56:18 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/31 01:00:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_stack_item	*set_stack(char *str)
{
	t_stack_item	*curr;
	int				temp_atoi;
	char			*temp_itoa;
	int				temp_con;

	temp_atoi = ft_atoi(str);
	temp_itoa = ft_itoa(temp_atoi);
	temp_con = !ft_strncmp(temp_itoa, str, ft_strlen(str));
	free(temp_itoa);
	if (temp_con)
		curr = create_stack_item(temp_atoi);
	else
		return (write_error("Error: invalid arguments"));
	if (!curr)
		return (write_error("Error: malloc null'd out"));
	return (curr);
}

void	create_stack_item_w_checks(t_stack_item *curr, char *content)
{
	int		temp_atoi;
	char	*temp_itoa;

	temp_atoi = ft_atoi(content);
	temp_itoa = ft_itoa(temp_atoi);
	if (!ft_strncmp(temp_itoa, content, ft_strlen(content)))
		curr->prev = create_stack_item(temp_atoi);
	else
		clear_stack(&curr);
	free(temp_itoa);
}

t_stack_item	*parse(int argc, char *argv[])
{
	t_stack_item	*curr;
	char			**args;
	int				i;

	args = get_all_args(argc, argv);
	i = 0;
	while (args[i])
		i++;
	curr = set_stack(args[--i]);
	if (!curr)
		return (NULL);
	while (--i >= 0)
	{
		create_stack_item_w_checks(curr, args[i]);
		if (!curr || !curr->prev)
			return (write_error("Error: malloc null'd out"));
		curr->prev->next = curr;
		curr = curr->prev;
	}
	while (args[++i])
		free(args[i]);
	free(args);
	if (!check_uniq(curr))
		return (write_error("Error: duplicate number found"));
	return (curr);
}
