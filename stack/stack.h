/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:02:44 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/23 19:20:03 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct s_stack_item
{
	unsigned int		index;
	int					content;
	struct s_stack_item	*prev;
	struct s_stack_item	*next;
}						t_stack_item;

t_stack_item	*create_stack_item(int content, unsigned int index);
void	*clear_stack(t_stack_item **stack);

#endif