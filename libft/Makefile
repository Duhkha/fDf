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
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c libft.h \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c ft_strsplit_2.c

COMPILED_FT = ft_strlen.o ft_strdup.o ft_strcat.o ft_strstr.o ft_strlcat.o ft_strnstr.o \
	ft_strrchr.o ft_strchr.o ft_tolower.o ft_toupper.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_memset.o ft_memcpy.o ft_memccpy.o ft_memchr.o \
	ft_memmove.o ft_strcmp.o ft_strncmp.o ft_atoi.o ft_bzero.o ft_strcpy.o \
	ft_isprint.o ft_memalloc.o ft_memdel.o ft_strncat.o ft_memcmp.o ft_strncpy.o \
	ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o \
	ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o libft.h.gch \
	ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o \
	ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	get_next_line.o ft_strsplit_2.o

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
