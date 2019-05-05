##
## EPITECH PROJECT, 2017
## makefile my_pushswap
## File description:
## mathieu gery
##

CC	=	gcc
SRC_DIR	=	$(realpath src)/
CHECK_D	=	$(realpath src/check)/
PATH_D	=	$(realpath src/path)/
PIPE_D	=	$(realpath src/pipe)/
BUILD_D	=	$(realpath src/builtins)/
INC	=	$(realpath include)/
SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)consol.c	\
		$(SRC_DIR)exec.c	\
		$(CHECK_D)check_str.c	\
		$(CHECK_D)check_pars.c	\
		$(CHECK_D)check.c	\
		$(PATH_D)access.c	\
		$(BUILD_D)my_cd.c	\
		$(BUILD_D)my_cd_errors.c\
		$(BUILD_D)exit.c	\
		$(BUILD_D)setenv.c	\
		$(BUILD_D)unsetenv.c	\
		$(PIPE_D)handle_sem.c	\
		$(PIPE_D)pipe_redir.c	\
		$(PIPE_D)pipe_error.c	\

LIB_DIR	=	$(realpath lib/my)/
LIB	=	my
LIBS	=	-L$(LIB_DIR) -l$(LIB)
OBJ	=	$(SRC:.c=.o)
NAME	=	mysh
CFLAGS +=	-Wall -W -Wextra -I$(INC)


all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re:	fclean all

debug:		CFLAGS += -g
debug:		re
