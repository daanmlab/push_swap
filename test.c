/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:01:49 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 21:50:43 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_stack_item *start = arg_parse(argc, argv);
    sort(start);
    print_stack(start);
    ft_putstr_fd("\n\nafter:\n", 1);
    start = swap_a(start);
    start = swap_a(start);
    print_stack(start);
    return (0);
}