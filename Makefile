# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jenne <jenne@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 16:32:01 by jpflegha          #+#    #+#              #
#    Updated: 2024/11/14 10:30:37 by jenne            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRC = ft_printf.c ft_print_ptr.c

OBJ = $(SRC:%.c=%.o) 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $?

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)

re : fclean all	