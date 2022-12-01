# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 18:25:58 by yonamog2          #+#    #+#              #
#    Updated: 2022/12/02 02:33:10 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FILES = checking.c create_list.c ft_split_comp.c main.c push.c reverse_rotate.c rotate.c swap.c utils.c utils2.c get_next_line.c get_next_line_utils.c

OBJ = $(FILES:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re