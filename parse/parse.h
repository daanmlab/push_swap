/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:02 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/30 19:27:44 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../libft/libft.h"
# include "../stack/stack.h"

t_stack_item	*parse(int argc, char *argv[]);
char			**get_all_args(int argc, char *argv[]);
int				is_sorted(t_stack_item **stack);
void			*write_error(char *error_message);
int				check_uniq(t_stack_item *start);

typedef struct s_temp_spice
{
	long		result;
	int			error;
	char		*next_ptr;
}				t_temp_spice;

#endif