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

all: intro $(NAME)

intro:
	@echo "---------------------------FILLIT----------------------------"
	@echo "COMPILATION FILLIT_SRC"
	@echo "[\c"

$(NAME): $(OBJ)
	@echo "]"
	@echo "FILLIT_SRC                 [DONE]"
	@echo "COMPILATION LIBFT"
	@make -C libft/ fclean && make -C libft/
	@$(CC) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft
	@echo "FILLIT                     [DONE]"
	@echo "-------------------------------------------------------------"
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "CLEAN                      [DONE]"
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "FCLEAN                     [DONE]"
re: fclean all

%.o: %.c
	@echo  ">\c"
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: all clean fclean re intro
