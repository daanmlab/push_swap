/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:40:24 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/26 01:10:42 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/stack.h"

void	prep_b(t_stack_item **stack_a, t_stack_item **stack_b);
void	prep_a(t_stack_item **stack_a, t_stack_item **stack_b);
void	find_all_bffs(t_stack_item **stack_a, t_stack_item **stack_b);
void	calc_all_cost(t_stack_item **stack_b);
int		get_moves_to_top_and_set_go_up(t_stack_item *node);