##
## EPITECH PROJECT, 2017
## Makefile libmy.a
## File description:
## mathieu gery
##

CC	=	gcc
SRC	=	my_putchar.c		\
		my_putstr.c		\
		str_cmp.c		\
		print_arr.c		\
		my_strlen.c		\
		my_strcat.c		\
		get_next_line.c		\
		array_size.c		\
		my_getnbr.c		\
		my_strncpy.c		\
		str_to_word_array.c	\
		str_to_word_array2.c

CFLAGS	+=	-I../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
