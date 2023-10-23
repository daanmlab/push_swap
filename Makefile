# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/23 19:44:07 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_LIB = push_swap.a



SRCS =  moves/swap.c \
		moves/push.c \
		moves/rotate.c \
		parse/parse.c \
		parse/sort.c \
		stack/stack_tools.c \
		test/put_pointer_addr.c \
		test/test_tools.c
		

OBJS = $(SRCS:.c=.o)

MAIN = main.c

TEST_MAIN = test/test_main.c

LIBFT = libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

TEST_ARGS = -8 -16

$(PUSH_SWAP_LIB): $(OBJS)
	@make -sC ./libft
	#@$(CC) -c $(FLAGS) $(SRCS)
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)

all : $(PUSH_SWAP_LIB)

test : $(PUSH_SWAP_LIB)
	@$(CC) $(FLAGS) $(TEST_MAIN) $(PUSH_SWAP_LIB) $(LIBFT) -o $(NAME)
	@./$(NAME) $(TEST_ARGS)
	@rm -rf $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -sC ./libft

fclean : clean
	@$(MAKE) fclean -sC ./libft
	rm -rf $(NAME) $(PUSH_SWAP_LIB)

fnorm :
	$(MAKE) fnorm -C ./moves
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) *.h
	norminette $(SRCS) *.h

re : fclean all%  