# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 07:25:05 by syoung            #+#    #+#              #
#    Updated: 2017/06/01 12:26:39 by syoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAMESO = libft.so

SRC = ft_strlen.c ft_strdup.c ft_strcat.c ft_strstr.c ft_strlcat.c ft_strnstr.c \
	ft_strrchr.c ft_strchr.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
	ft_memmove.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_bzero.c ft_strcpy.c \
	ft_isprint.c ft_memalloc.c ft_memdel.c ft_strncat.c ft_memcmp.c ft_strncpy.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c ft_abs.c

COMPILED_FT = ${SRC:c=o}

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

so: 
	gcc -shared -o $(NAMESO) -fPIC $(SRC)
$(NAME):
	gcc -c $(SRC) $(FLAGS)
	ar rc $(NAME) $(COMPILED_FT)

clean:
	/bin/rm -f $(COMPILED_FT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

#test: 
#	gcc main.c -L. -lft $(FLAGS)
