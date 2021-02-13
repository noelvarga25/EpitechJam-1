##
## EPITECH PROJECT, 2021
## EpitechJam-1
## File description:
## Makefile
##

P_CORE		=	src/Core
P_GAME		=	src/Game
P_UIOBJECT	=	src/UIObject

SRC			=	$(P_CORE)/Data.cpp \
				$(P_CORE)/Object.cpp \
				$(P_CORE)/App.cpp \
				$(P_GAME)/Engine.cpp \
				$(P_GAME)/Scene.cpp \
				$(P_UIOBJECT)/Anim.cpp \
				$(P_UIOBJECT)/Button.cpp \
				$(P_UIOBJECT)/Entry.cpp \
				$(P_UIOBJECT)/Menu.cpp \
				src/Tool.cpp \
				src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Iinclude

NAME		=	"Monkey Time Warp 3"

all:		$(NAME)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

windows:
			g++ -o $(NAME) $(OBJ) -ISFML-WIN/include -LSFML-WIN/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all