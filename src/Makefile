NAME = mlx

SRC = main.c \
	draw.c \
	read.c

OBJ = ${SRC:c=o}

LIBFT = ../libft/libft.a

MINILIBX_LINUX = ../minilibx/libmlx.a
FLAGS = -framework Opengl -framework Appkit -Werror -Wextra -Wall

FLAGSLINUX = -L/usr/X11/lib -lmlx -lXext -lX11 -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) $(FLAGS)

linux: 
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(FLAGSLINUX)

clean:
	/bim/rm -f $(OBJ)

fclean: clean
	/bim/rm -f $(NAME)

re: fclean all
##mac:
##	gcc -o mlx main.c draw.c read.c ../libft/libft.a ../minilibx_macos/libmlx.a -framework Opengl -framework Appkit

##linux:
##	gcc -o mlx main.c draw.c read.c ../libft/libft.a -L/usr/X11/lib -lmlx -lXext -lX11

