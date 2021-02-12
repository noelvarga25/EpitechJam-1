##
## EPITECH PROJECT, 2021
## EpitechJam-1
## File description:
## Makefile
##

P_CORE		=	src/Core
P_GAME		=	src/Game

SRC			=	$(P_CORE)/Data.cpp \
				$(P_CORE)/Object.cpp \
				$(P_GAME)/Engine.cpp \
				src/Tool.cpp \
				src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude -ISFML-WIN/include

NAME		=	game

all:		$(NAME)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) -LSFML-WIN/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all