# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 18:25:58 by yonamog2          #+#    #+#              #
#    Updated: 2022/12/02 02:46:05 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BON = checker

FILES = checking.c cost.c create_list.c do_move.c ft_split_comp.c main.c position.c push.c reverse_rotate.c rotate.c sort_tiny.c sort.c stack.c swap.c utils.c utils2.c

BONUS_FILES = bonus_checking.c bonus_create_list.c bonus_ft_split_comp.c bonus_get_next_line.c bonus_get_next_line_utils.c bonus_main.c bonus_push.c bonus_reverse_rotate.c bonus_rotate.c bonus_swap.c bonus_utils.c bonus_utils2.c

OBJ = $(FILES:.c=.o)

OBJ_BONUS = $(BONUS_FILES:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BON)

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BON)

re: fclean all

.PHONY: all clean fclean re