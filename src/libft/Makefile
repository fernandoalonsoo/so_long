# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 17:35:23 by fealonso          #+#    #+#              #
#    Updated: 2024/09/25 14:50:58 by fealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = src/ft_isalpha.c \
           src/ft_memcmp.c \
           src/ft_strnstr.c \
           src/ft_atoi.c \
           src/ft_isascii.c \
           src/ft_memcpy.c \
           src/ft_memmove.c \
           src/ft_strlcat.c \
           src/ft_strrchr.c \
           src/ft_bzero.c \
           src/ft_isdigit.c \
           src/ft_memset.c \
           src/ft_strlcpy.c \
           src/ft_isprint.c \
           src/ft_strchr.c \
           src/ft_strlen.c \
           src/ft_tolower.c \
           src/ft_isalnum.c \
           src/ft_memchr.c \
           src/ft_strdup.c \
           src/ft_strncmp.c \
           src/ft_toupper.c \
           src/ft_calloc.c \
           src/ft_substr.c \
           src/ft_strjoin.c \
           src/ft_strtrim.c \
           src/ft_itoa.c \
           src/ft_split.c \
           src/ft_strmapi.c \
           src/ft_striteri.c \
           src/ft_putchar_fd.c \
           src/ft_putstr_fd.c \
           src/ft_putendl_fd.c \
           src/ft_putnbr_fd.c


BONUSSRCS = src/ft_lstnew.c \
                src/ft_lstadd_front.c \
                src/ft_lstsize.c \
                src/ft_lstlast.c \
                src/ft_lstadd_back.c \
                src/ft_lstdelone.c \
                src/ft_lstclear.c \
                src/ft_lstiter.c \
                src/ft_lstmap.c


OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUSOBJS)
	ar rcs $(NAME) $(OBJS) $(BONUSOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus
