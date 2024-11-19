NAME = fdf

CC = cc -Wall -Wextra -Werror

RM = rm -f

SRC = main.c

OBJ = ${SRC:.c=.o}

MLX_PATH = minilibx/
LIB_MLX = $(MLX_PATH)libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB_MLX)
	$(CC) $(OBJ) $(LIB_MLX) -o $(NAME) -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -c $< -o $@

$(LIB_MLX):
	make -C $(MLX_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re