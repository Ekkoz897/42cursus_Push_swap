NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c

OBJ = $(SRC: .c = .o)

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run:
	./push_swap 3 1 2 4 5 6

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./so_long maps/map3.ber