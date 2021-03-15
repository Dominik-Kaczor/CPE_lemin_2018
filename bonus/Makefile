##
## EPITECH PROJECT, 2018
## Lemin
## File description:
## Makefile
##

SRC		=	src/main.c \
			src/buttons.c	\
			src/parsing.c	\
			src/tools.c	\
			src/wiewer.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -lcsfml-window -lcsfml-system	\
			-lcsfml-graphics -lcsfml-audio

CPPFLAGS	=	-I./include/

LIB		=	-L./lib/my/ -lmy

NAME		=	wiewer

DEPS	=	include/my.h

CC		=	gcc

RM		=	rm -rf

all:		lib $(NAME)

debug:	CFLAGS += -g3
debug: 	re

$(NAME):	$(OBJ)
		$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
		mv wiewer ../
clean:
		$(RM) $(OBJ)

fclean:	clean lib_clean
		$(RM) $(NAME)
		$(RM) *.dSYM

re:		fclean all

lib:
		@make --no-print-directory re -C ./lib
		@make --no-print-directory clean -C ./lib

lib_clean:
		@make --no-print-directory fclean -C ./lib

.PHONY:		all clean fclean re lib lib_clean
