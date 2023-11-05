/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:56:43 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/05 16:04:08 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_main.h"
#include <unistd.h>

static int	ft_strlen_nl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen_nl(s1) + ft_strlen_nl(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	free(s1);
	result[i + j] = '\0';
	return (result);
}

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

void	buffer_fix(char *nl_pointer, char *buffer)
{
	if (nl_pointer[1] == '\0')
		clean_buffer(buffer);
	else
		ft_strlcpy(buffer, nl_pointer + 1, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	char		*nl_pointer;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		clean_buffer(buffer);
		return (NULL);
	}
	result = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		nl_pointer = ft_strchr(buffer, '\n');
		result = ft_strjoin_nl(result, buffer);
		if (nl_pointer)
		{
			buffer_fix(nl_pointer, buffer);
			break ;
		}
		else
			clean_buffer(buffer);
	}
	return (result);
}

// #include <fcntl.h>
// int main(void)
// {
//     int fd;
//     char *result;

//     fd = open("multiple_line_w_nl.txt", O_RDONLY);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     result = get_next_line(fd);
//     printf("final: %s\n", result);
//     free(result);
//     return (0);
// }
