/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:43:13 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/25 00:51:08 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../stack/stack.h"
#include "test.h"

void	print_stack_item(t_stack_item *stack_item)
{
	if (!stack_item)
	{
		ft_putstr_fd("null", 1);
		return ;
	}
	ft_putstr_fd("-----------------\n", 1);
	ft_putstr_fd("addres:  ", 1);
	put_pointer_addr(stack_item);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("index:   ", 1);
	ft_putnbr_fd(stack_item->index, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("content: ", 1);
	ft_putnbr_fd(stack_item->content, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("cost:    ", 1);
	ft_putnbr_fd(stack_item->cost, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("go_up:   ", 1);
	ft_putnbr_fd(stack_item->go_up, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("bff->content: ", 1);
	if (stack_item->bff)
		ft_putnbr_fd(stack_item->bff->content, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("prev:    ", 1);
	put_pointer_addr(stack_item->prev);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("next:    ", 1);
	put_pointer_addr(stack_item->next);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("-----------------\n", 1);
}

void	print_stack(t_stack_item *stack)
{
	t_stack_item	*curr;

	curr = stack;
	if (!curr)
		return ;
	while (curr)
	{
		print_stack_item(curr);
		curr = curr->next;
	}
}
