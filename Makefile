# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/01/27 15:29:58 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRC = ft_printf.c ./tests/main.c print_c.c print_format.c save_format.c sp_cases.c

FLAGS = -Werror -Wall -Wextra

CFLAGS = -g

INCL = Iincludes/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@echo "Library created"
	gcc -o $(NAME) $(OBJ) $(FLAGS) -L libft/ -lft
	@echo "Compiled"

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all
