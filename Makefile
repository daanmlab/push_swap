# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/22 23:48:10 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_LIB = push_swap.a



SRCS =  parse.c \
		test_tools.c \
		put_pointer_addr.c \
		sort.c \
		stack_tools.c

OBJS = $(SRCS:.c=.o)

MAIN = main.c

TEST_MAIN = test.c

LIBS = libft/libft.a \
		moves/moves.a

CC = cc

FLAGS = -Wall -Wextra -Werror

TEST_ARGS = -8 -16

$(NAME): $(OBJS)
	@make -C ./libft
	@make -C ./moves
	@$(CC) -c $(FLAGS) $(SRCS)
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)

all : $(NAME)

test : $(NAME)
	@$(CC) $(FLAGS) $(TEST_MAIN) $(PUSH_SWAP_LIB) $(LIBS)  -o $(NAME)
	@./$(NAME) $(TEST_ARGS)
	@rm -rf $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./moves

fclean : clean
	@$(MAKE) fclean -sC ./libft
	@$(MAKE) fclean -sC ./moves
	rm -rf $(NAME) $(PUSH_SWAP_LIB)

fnorm :
	$(MAKE) fnorm -C ./moves
	@$(MAKE) -s fclean
	@python3 -m c_formatter_42 $(SRCS) *.h
	norminette $(SRCS) *.h

re : fclean all%  