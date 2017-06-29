all:
	(cd libft; make)
	(cd src; make)
	(cd minilibx_macos; make)

clean:
	(cd libft; make clean)
	(cd src; make clean)

fclean:
	(cd libf; make fclean)
	(cd src; make fclean)

re: fclean all
