NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) 	$(OBJ)

clean: 
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
