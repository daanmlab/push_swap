/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:57:18 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 16:03:19 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MAIN_H
# define BONUS_MAIN_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		check(char *move);
char	*get_next_line(int fd);

#endif
