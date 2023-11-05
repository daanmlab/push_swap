/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:34:36 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/30 19:36:53 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_sorted(t_stack_item **stack)
{
	t_stack_item	*curr;

	curr = (*stack)->next;
	while (curr)
	{
		if (curr->content < curr->prev->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}
