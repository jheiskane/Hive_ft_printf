# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2021/12/17 16:04:58 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = ../ft_printf.c main.c

INCL = ../ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -ggdb  $(SRC) -L. -lft

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: clean all
