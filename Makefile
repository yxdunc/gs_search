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
