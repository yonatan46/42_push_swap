# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 22:37:44 by yonamog2          #+#    #+#              #
#    Updated: 2022/11/20 14:53:41 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main
FILES = main.c test1.c test2.c
OBJ = $(FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	cd ft_printf && make
	$(CC) $(CFLAGS) $(FILES) ./ft_printf/libft.a -o $(NAME)
clean: 
	cd ft_printf && make clean
	rm -rf $(OBJ) 
fclean: clean
	cd ft_printf && make fclean
	rm -rf $(NAME)
re: fclean all 

.PHONY: all clean fclean re 