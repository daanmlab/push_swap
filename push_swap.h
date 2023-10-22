/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:08:10 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 23:25:38 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "moves/moves.h"
#include <unistd.h>


int						put_pointer_addr(void *p);
void					print_stack_item(t_stack_item *stack_item);
void					print_stack(t_stack_item *stack);
t_stack_item			*create_stack_item(int content, unsigned int index);
void					*clear_stack(t_stack_item **stack);
t_stack_item			*arg_parse(int argc, char *argv[]);
void					sort(t_stack_item *start);
