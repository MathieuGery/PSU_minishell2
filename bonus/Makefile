##
## EPITECH PROJECT, 2017
## makefile my_pushswap
## File description:
## mathieu gery
##

SRC	=	../main.c			\
		consol.c			\
		../src/access.c			\
		../src/my_cd.c			\
		../src/check_str.c		\
		../src/setenv.c			\
		../src/check.c

NAME	=	mysh

all:	$(NAME)

$(NAME):
	make -C ../lib/my
	gcc -g -o $(NAME) $(SRC) -I../include -L../lib/my -lmy

clean:
	make clean -C ../lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C ../lib/my

re:	fclean all
