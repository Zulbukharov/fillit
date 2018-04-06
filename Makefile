NAME = fdf

SRC = main.c count.c init_and_drow.c preprcessing.c rotate_and_draw.c

OBJ = $(SRC:.c=.o)

MAKELIB = make -C libftprintf/

LIBPATH = libftprintf/libftprintf.a

MLX = -I minilibx -lmlx -framework OpenGL -framework AppKit

SFLAG = -c -O3 -Os -Wall -Wextra -Werror

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH) $(OBJ)
    gcc  -o $(NAME) -O3 -Os -Wall -Wextra -Werror $(OBJ) $(LIBPATH) $(MLX)

$(LIBPATH): 
    make -C libftprintf/

%.o: %.c
    gcc $(SFLAG)  $< -o $@

clean: 
    rm -f $(OBJ)
    make -C libftprintf/ clean

fclean: clean
    rm -f $(NAME)
    make -C libftprintf/ fclean

re: fclean all
