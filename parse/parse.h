/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:31:02 by dabalm            #+#    #+#             */
/*   Updated: 2023/10/23 19:27:01 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../stack/stack.h"

t_stack_item	*arg_parse(int argc, char *argv[]);
void	sort(t_stack_item *start);
#endif