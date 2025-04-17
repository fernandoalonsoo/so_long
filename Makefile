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

# Printf
PRINTF_DIR = src/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC =		src/so_long.c \
			src/functions/validation.c \
			src/functions/map.c \
			src/functions/validate_map.c \
			src/functions/flood_fill.c \
			src/functions/game_settings.c \
			src/functions/input.c \
			src/functions/ft_print_string.c \
			src/get_next_line/src/get_next_line.c \
			src/get_next_line/src/get_next_line_utils.c

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) -no-pie $(INCLUDES) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all
