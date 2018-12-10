# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pharatyk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:34:32 by pharatyk          #+#    #+#              #
#    Updated: 2018/11/06 16:34:34 by pharatyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
SRCS = ./SRC/tabloteur.c ./SRC/main.c
CC = gcc -Wall -Wextra -Werror
CFLAGS = -I ./includes/ -I ./libft/includes/
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/ fclean && make -C libft/
		$(CC) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft
clean:
		rm -f $(OBJ)
		make -C libft/ clean
fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean
re: fclean all

.PHONY: all clean fclean re
