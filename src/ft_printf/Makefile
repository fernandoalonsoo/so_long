
# Nombre del archivo final (libreria estatica)
NAME = libftprintf.a

# Nombre del compilador y flags con las que se va a compilar
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Listado de archivos fuente .c obligatorios
SRCS =		src/ft_printf.c \
			src/functions/ft_print_char.c \
			src/functions/ft_print_string.c \
			src/functions/ft_print_pointer.c \
			src/functions/ft_print_number.c \
			src/functions/ft_print_unsigned.c \
			src/functions/ft_print_hex.c \
			src/functions/aux/ft_itoa.c \
			src/functions/aux/ft_strlen.c \

# Listado de archivos fuente .c del bonus
BONUSSRCS = 

# Convierte los archivos fuente en archivos objeto
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

# Regla principa: construye el archivo definido en NAME
all: $(NAME)

# Cómo construir NAME a partir de los objetos
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regla para incluir los bonus en la compilación
# bonus: $(OBJS) $(BONUSOBJS)
#	ar rcs $(NAME) $(OBJS) $(BONUSOBJS)

# Regla genérica para convertir .c a .o
# $<: Input (archivo fuente)
# $@: Output (archivo objeto)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto generados
clean:
	rm -f $(OBJS) $(BONUSOBJS)

# Regla para limpiar todo (incluye el archivo final)
fclean: clean
	rm -f $(NAME)

# Regla para recompilar desde cero
re: fclean all

# Regla para recompilar todo, incluyendo los bonus
rebonus: fclean bonus

# Evitar conflictos en caso de que haya archivos con el mismo nombre
.PHONY: all clean fclear