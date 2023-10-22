/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:49 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 22:24:18 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_stack_item *start = arg_parse(argc, argv);
    t_stack_item **stack_a = &start;
    sort(*stack_a);
    print_stack(*stack_a);
    ft_putstr_fd("\n\nafter:\n", 1);
    swap_a(stack_a);
    // swap_a(stack_a);
    print_stack(*stack_a);
    return (0);
}