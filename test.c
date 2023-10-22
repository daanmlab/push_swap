/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:49 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 23:52:01 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack_item *start_a = arg_parse(argc, argv);
    t_stack_item *start_b = NULL;
    if (!start_a)
        return (0);
    t_stack_item **stack_a = &start_a;
    t_stack_item **stack_b = &start_b;
    sort(*stack_a);
    ft_putstr_fd("stack_a:\n", 1);
    print_stack(*stack_a);
    ft_putstr_fd("stack_b:\n", 1);
    print_stack(*stack_b);
    ft_putstr_fd("\n\nafter:\n", 1);
    push(stack_a, stack_b);
    reverse_rotate(stack_a);
    ft_putstr_fd("stack_a:\n", 1);
    print_stack(*stack_a);
    ft_putstr_fd("stack_b:\n", 1);
    print_stack(*stack_b);
    return (0);
}