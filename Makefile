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

NAME = fillit
SRCS = ./SRC/tabloteur.c ./SRC/main.c ./SRC/solve.c ./SRC/tools.c
CC = gcc -Wall -Wextra -Werror
CFLAGS = -I ./SRC/ -I ./libft/
OBJ = $(SRCS:.c=.o)

all: .masterstealth $(NAME)

.masterstealth:
	@echo "---------------------------FILLIT----------------------------"
	@echo "COMPILATION FILLIT_SRC"
	@echo "[\c"
	@touch .masterstealth

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
	@rm -f .masterstealth
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

.PHONY: all clean fclean re
