NAME = fdf

SRC = main.c make_lists.c fdf.c get_coord.c draw.c

SRCO = main.o make_lists.o fdf.o get_coord.o draw.o

CFLAGS = -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(CFLAGS) $(NAME) $(SRC) libft/libft.a -lmlx -framework OpenGL -framework AppKit
clean:
	rm -f $(SRCO)
	make -C libft/ clean
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
re: fclean all
