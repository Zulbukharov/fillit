NAME = fillit
SRC = valid.c main.c list_functions.c list_functions2.c ft_sqrt.c map_fill.c 
MAKELIB = make -C libft/
LIBPATH = libft/libft.a
EFLAGS = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH)
	gcc -o $(NAME) $(EFLAGS) $(SRC) $(LIBPATH)

$(LIBPATH):
	$(MAKELIB)

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

