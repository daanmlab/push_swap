# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/26 01:07:13 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_LIB = push_swap.a



SRCS =  moves/swap.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse_rotate.c \
		parse/parse.c \
		stack/stack_tools.c \
		test/put_pointer_addr.c \
		test/test_tools.c \
		main/prep.c \
		main/bff.c \
		main/cost.c
		

OBJS = $(SRCS:.c=.o)

MAIN = main.c

TEST_MAIN = test/test_main.c

LIBFT = libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

TEST_ARGS = 12 -200 23 -40 5 2 8 1 9

$(PUSH_SWAP_LIB): $(OBJS)
	@make -sC ./libft
	#@$(CC) -c $(FLAGS) $(SRCS)
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)

all : $(PUSH_SWAP_LIB)

test : $(PUSH_SWAP_LIB) $(MAIN)
	$(CC) $(FLAGS) $(MAIN) $(PUSH_SWAP_LIB) $(LIBFT) -o $(NAME)
	./$(NAME) $(TEST_ARGS)
	./push_swap_visualizer/build/bin/visualizer

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -sC ./libft

fclean : clean
	@$(MAKE) fclean -sC ./libft
	rm -rf $(NAME) $(PUSH_SWAP_LIB)

fnorm :
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) */*.h
	norminette $(SRCS) */*.h

re : fclean all