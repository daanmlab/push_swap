/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:59:33 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 16:04:53 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_main.h"

int	check(char *move)
{
	return (!ft_strncmp(move, "pa\n", 10) || !ft_strncmp(move, "pb\n", 10)
		|| !ft_strncmp(move, "rrb\n", 10) || !ft_strncmp(move, "rra\n", 10)
		|| !ft_strncmp(move, "rrr\n", 10) || !ft_strncmp(move, "rb\n", 10)
		|| !ft_strncmp(move, "ra\n", 10) || !ft_strncmp(move, "rr\n", 10)
		|| !ft_strncmp(move, "sa\n", 10) || !ft_strncmp(move, "sb\n", 10)
		|| !ft_strncmp(move, "ss\n", 10));
}
