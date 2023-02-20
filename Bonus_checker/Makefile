NAME = checker

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

SRC = checker.c  checker_utils.c movements1.c movements2.c movements3.c ../Get_next_line/get_next_line.c ../Get_next_line/get_next_line_utils.c \
		

all:	$(NAME)

$(NAME): $(SRC)
	@make -s -C ../
	@make -s -C ../libft
	@make -s -C ../ft_printf
	@$(CC) $(CFLAGS) $(SRC) ../libft/libft.a ../ft_printf/libftprintf.a -o $(NAME)

run: $(NAME)
	@../push_swap 3 2 1 | ./checker 3 2 1

clean:
	@find . -type f \( -name "*.o" \) -delete

fclean: clean
	@find . -type f \( -name "*.a" \) -delete

re: fclean all