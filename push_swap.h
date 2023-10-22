/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:08:10 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 00:43:36 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>

typedef struct s_stack_item
{
	unsigned int			index;
	struct	s_stack_item	*prev;
	struct	s_stack_item	*next;
	int						content;
} t_stack_item;

int	put_pointer_addr(void *p);
void print_stack_item(t_stack_item *stack_item);
void print_stack(t_stack_item *stack);