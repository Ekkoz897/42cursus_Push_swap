NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRC = push_swap.c push_utils.c movements.c

OBJ = $(SRC: .c = .o)

all:	$(NAME)

$(NAME): $(SRC)
	@echo "\nCompiling the program files...\n"
	@make -s -C libft
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

run: all
	@./push_swap 2 1 3 5 4 6 

clean:
	@find . -type f \( -name "*.o" \) -delete

fclean: clean
	@find . -type f \( -name "*.a" -o -name "push_swap" \) -delete

re: fclean all

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 5 4 6 