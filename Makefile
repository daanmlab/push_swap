# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/11/01 19:00:39 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

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

SRCS_BONUS =	stack/stack_tools.c \
				parse/parse_utils.c \
				parse/parse.c \
				moves/swap.c \
				moves/push.c \
				moves/rotate.c \
				moves/reverse_rotate.c \
				main/prep_utils.c \
				bonus/get_next_line.c \
				bonus/utils.c \
				bonus/main.c

MAIN = main.c

TEST_MAIN = test/test_main.c

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(SRCS)
	@make -sC ./libft
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all : $(NAME)

bonus: $(SRCS_BONUS)
	@make -sC ./libft
	@$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS)


clean :
	$(MAKE) clean -sC ./libft

fclean : clean
	@$(MAKE) fclean -sC ./libft
	rm -rf $(NAME)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) $(SRCS_BONUS) */*.h
	norminette $(SRCS) $(SRCS_BONUS) */*.h

re : fclean all