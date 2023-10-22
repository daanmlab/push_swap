/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 22:50:48 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/22 23:46:49 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>

typedef struct s_stack_item
{
	unsigned int		index;
	struct s_stack_item	*prev;
	struct s_stack_item	*next;
	int					content;
}						t_stack_item;

void	push(t_stack_item **src, t_stack_item **dest);
void		swap_a(t_stack_item **stack_a);
void		swap_b(t_stack_item **stack_b);
void		swap_both(t_stack_item **a, t_stack_item **b);
void	rotate(t_stack_item **stack);
void	reverse_rotate(t_stack_item **stack);