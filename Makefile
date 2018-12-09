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
SRCS = ./tabloteur.c
# CC = gcc -Wall -Wextra -Werror
# CFLAGS = -I ./includes/
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		gcc -Wall -Wextra -Werror -I libft/includes -o $(OBJ) -c $(SRCS)
		gcc -o filler $(OBJ) -I libft/includes -L libft/ -lft
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re