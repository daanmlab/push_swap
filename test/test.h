/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:10:34 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/23 19:26:27 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "../stack/stack.h"

int	put_pointer_addr(void *p);
void	print_stack_item(t_stack_item *stack_item);
void	print_stack(t_stack_item *stack);
#endif