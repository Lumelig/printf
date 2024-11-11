# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 16:32:01 by jpflegha          #+#    #+#              #
#    Updated: 2024/11/11 14:53:48 by jpflegha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRC = ft_printf.c

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