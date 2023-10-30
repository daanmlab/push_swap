# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/30 19:36:01 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_LIB = push_swap.a

SRCS =  moves/swap.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse_rotate.c \
		parse/parse.c \
		parse/parse_utils.c \
		stack/stack_tools.c \
		main/prep.c \
		main/prep_utils.c \
		main/bff.c \
		main/cost.c \
		main.c 	

MAIN = main.c

TEST_MAIN = test/test_main.c

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(SRCS)
	@make -sC ./libft
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -sC ./libft

fclean : clean
	@$(MAKE) fclean -sC ./libft
	rm -rf $(NAME)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) */*.h
	norminette $(SRCS) */*.h

re : fclean all