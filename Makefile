# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Rutas de includes
INCLUDES = -Iinclude -Imlx -Ilibft

# Librerías
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

# Fuentes y objetos
SRC = src/so_long.c src/functions/validation.c
OBJ = $(SRC:.c=.o)

# Nombre del ejecutable
NAME = so_long

# Libft
LIBFT_DIR = src/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =		src/so_long.c \
			src/functions/validation.c \
			src/functions/map.c \
			src/functions/validate_map.c \
			src/functions/flood_fill.c \
			src/functions/game_settings.c \
			src/functions/input.c \
			src/get_next_line/src/get_next_line.c \
			src/get_next_line/src/get_next_line_utils.c

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
