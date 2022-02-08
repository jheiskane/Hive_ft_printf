# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 09:59:08 by smarvin           #+#    #+#              #
#    Updated: 2022/02/08 11:02:12 by jheiskan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -g -Wall -Wextra -Werror

SRCS =	ft_atoi.c\
		ft_isdigit.c\
		ft_printf.c\
		ft_strchr.c\
		ft_strncpy.c\
		print_c.c\
		ft_strnew.c\
		ft_strsub.c\
		sp_cases.c\
		print_format.c\
		print_p.c\
		ft_itoa_base.c\
		save_format.c\
		print_s.c\
		ft_bzero.c\
		ft_strlen.c\
		print_diouxX.c\
		ft_toupper.c\
		ft_itoa_float.c\
		ft_strjoin.c\
		ft_strcat.c\
		print_f.c\
		ft_strcpy.c\
		ft_memalloc.c

OBJ_NAME = $(SRCS:.c=.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf.a created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I./includes -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "Removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removed libftprintf.a"

re: fclean all

.PHONY: all clean fclean re
