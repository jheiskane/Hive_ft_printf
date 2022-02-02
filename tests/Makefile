# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/02/01 13:26:50 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRC = main.c
FLAGS = -Werror -Wall -Wextra
CFLAGS = -g
INCL = Iincludes/
OBJ = $(SRC:.c=.o)

all: test $(NAME)

test:
	cd ../ && make re
	@mv ../libftprintf.a ./
	@echo "libftprintf.a moved to test folder"

$(NAME): $(OBJ)
#make -C libft/ "These lines are if there is no libft created yet"
#@echo "Library created"
	gcc -ggdb -Wall -Wextra -Werror $(SRC) -L. -lftprintf -o $(NAME)
	@echo "Compiled"
clean:
#make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
#make -C libft/ fclean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	/bin/rm -f libftprintf.a

re: fclean all
