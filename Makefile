all:
	(cd src; make)
	(cd libft; make)

clean:
	(cd src; clean)
	(cd libt; clean)

fclean:
	(cd src; fclean)
	(cd libft; clean)

re: fclean all