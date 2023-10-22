# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 22:54:09 by dabalm            #+#    #+#              #
#    Updated: 2023/10/22 23:11:59 by dabalm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = moves.a

SRCS =  swap.c \
		push.c \
		rotate.c

OBJS = $(SRCS:.c=.o)

CC = cc

FLAGS = -c -Wall -Wextra -Werror

TEST_ARGS = -8 -16 1

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(SRCS)
	@ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

fnorm :
	@make -s fclean
	@python3 -m c_formatter_42 $(SRCS) *.h
	norminette $(SRCS) *.h

re : fclean all%