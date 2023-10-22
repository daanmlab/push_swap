# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/22 01:02:05 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  parse.c \
		test_tools.c \
		put_pointer_addr.c

LIBFT = libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

TEST_ARGS = 9 2 9 3 3 5 3 -3 2

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all : $(NAME)

test : $(NAME)
	./$(NAME) $(TEST_ARGS)
	rm -rf $(NAME)

clean :
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all%  