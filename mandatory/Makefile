# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 18:25:58 by yonamog2          #+#    #+#              #
#    Updated: 2022/12/01 18:25:59 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = checking.c cost.c create_list.c do_move.c ft_split_comp.c main.c position.c push.c reverse_rotate.c rotate.c sort_tiny.c sort.c stack.c swap.c utils.c utils2.c

OBJ = $(FILES:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re