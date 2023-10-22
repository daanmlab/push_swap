/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:05:22 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 23:34:24 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	push(t_stack_item **src, t_stack_item **dest)
{
    t_stack_item *temp;
	if (!(*src))
        return;
    if (!(*dest))
    {
        temp = (*src)->next;
        *dest = *src;
        (*src)->next->prev = NULL;
        (*dest)->next = NULL;
        *src = temp;
        return ;
    }
    temp = (*src)->next;
    (*dest)->prev = *src;
    (*src)->next = *dest;
    *dest = *src;
    *src = temp;
}

