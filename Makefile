#	3 numbers -> 2 or 3 moves
#	5 numbers -> <=12 moves
#	100 numbers:
#		<700 moves = 5pts
#		<900 numbers = 4pts
#		<1,100 numbers = 3pts
#		<1,300 numbers = 2pts
#		<1,500 numbers = 1pts
#	500 numbers:
#		<5,500 moves = 5pts
#		<7,000 moves = 4pts
#		<8,500 moves = 3pts
#		<10,000 moves = 2pts
#		<11,500 moves = 1pts

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRC = SRC/push_swap.c SRC/push_utils.c SRC/push_utils2.c SRC/movements.c SRC/movements2.c \
		SRC/movements3.c SRC/sort.c SRC/sort_big.c SRC/fewer_moves.c SRC/first_element.c

OBJ = $(SRC: .c = .o)

all:	$(NAME)

$(NAME): $(SRC)
	@echo "\nCompiling the program files...\n"
	@make -s -C libft
	@make -s -C ft_printf
	@$(CC) $(CFLAGS) $(SRC) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

run: all
	./push_swap

clean:
	@find . -type f \( -name "*.o" \) -delete

fclean: clean
	@find . -type f \( -name "*.a" -o -name "push_swap" \) -delete

re: fclean all

valgrind:	all
	valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 4 5

git:	$(SRC)
	@git add .
	@git commit
	git push