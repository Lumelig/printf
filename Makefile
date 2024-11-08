# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 16:32:01 by jpflegha          #+#    #+#              #
#    Updated: 2024/11/08 15:45:46 by jpflegha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRC = 

OBJ = $(SRC:%.c=%.o) 

all : $(OBJ)
	ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $?

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)

re : fclean all	