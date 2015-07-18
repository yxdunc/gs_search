# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rguignar <rguignar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 23:25:02 by rguignar          #+#    #+#              #
#    Updated: 2013/12/15 23:25:41 by rguignar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = hotrace

FLAG = -Werror -Wall -Wextra -g # -O3

SRC = main.c minilib1.c minilib2.c get_next_line.c

RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
