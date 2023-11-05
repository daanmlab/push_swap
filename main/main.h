/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:40:24 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 15:54:38 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "../stack/stack.h"

void			prep_b(t_stack_item **stack_a, t_stack_item **stack_b);
void			prep_a(t_stack_item **stack_a);
void			find_all_bffs(t_stack_item **stack_a, t_stack_item **stack_b);
void			calc_all_cost(t_stack_item **stack_b);
int				get_moves_to_top_and_set_go_up(t_stack_item *node);
t_stack_item	*get_smallest_cost(t_stack_item **stack_b);
int				is_sorted(t_stack_item **stack);

#endif