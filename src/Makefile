

INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(shell pkg-config --libs --static mlx)

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all

#gcc -o test1 main.c -L/usr/X11/lib -lmlx -lXext -lX11
