# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/22 17:43:29 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PUSH_SWAP_LIB = push_swap.a

SRCS =  parse.c \
		test_tools.c \
		put_pointer_addr.c \
		sort.c

OBJS = $(SRCS:.c=.o)

MAIN = main.c

TEST_MAIN = test.c

LIBFT = libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

TEST_ARGS = -8 -16 -10 8 2 -1 7 6

$(NAME): $(OBJS)
	@make -C ./libft
	@cp $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(SRCS)
	@ar rcs $(PUSH_SWAP_LIB) $(OBJS)

all : $(NAME)

test : $(NAME)
	@$(CC) $(FLAGS) $(TEST_MAIN) $(PUSH_SWAP_LIB) -o $(NAME)
	./$(NAME) $(TEST_ARGS)
	@rm -rf $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME) $(PUSH_SWAP_LIB)

fnorm :
	make fclean
	python3 -m c_formatter_42 $(SRCS) *.h
	norminette $(SRCS) *.h

re : fclean all%  