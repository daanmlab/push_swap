# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/11/05 16:18:24 by dabalm           ###   ########.fr        #
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

SRCS_BONUS =	bonus/stack/stack_tools.c \
				bonus/parse/parse_utils.c \
				bonus/parse/parse.c \
				bonus/moves/swap.c \
				bonus/moves/push.c \
				bonus/moves/rotate.c \
				bonus/moves/reverse_rotate.c \
				bonus/main/prep_utils.c \
				bonus/get_next_line.c \
				bonus/utils.c \
				bonus/main.c

MAIN = main.c

TEST_MAIN = test/test_main.c

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(SRCS)
	@$(MAKE) -sC ./libft
	@echo "Creating $(NAME)"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(SRCS_BONUS)
	@$(MAKE) -sC ./libft
	@echo "Creating $(NAME_BONUS)"
	@$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean :
	$(MAKE) clean -sC ./libft

fclean :
	@$(MAKE) fclean -sC ./libft
	@echo "Cleaning $(NAME)"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) $(SRCS_BONUS) */*.h
	norminette $(SRCS) $(SRCS_BONUS) */*.h

re : fclean all

.PHONY : clean fclean fnorm re all bonus