##
## EPITECH PROJECT, 2023
## B-OOP-400-LYN-4-1-arcade-lucas.siraux
## File description:
## Makefile
##

CXX	=	g++

INC	=	-I src/

CXXFLAGS	+=	-Wall -Wextra -pedantic -std=c++17 -fPIC

LDFLAGS	=	-ldl

## arcade

NAME	=	arcade

SRC_DIR	=	./

SRC	=	$(SRC_DIR)Main.cpp	\
		$(SRC_DIR)Core.cpp	\
		$(SRC_DIR)libLoader.cpp

OBJ	=	$(SRC:.cpp=.o)

## NCURSES

NAME_NCURSES	=	lib/arcade_ncurses.so

SRC_NCURSES	=	$(SRC_DIR)Graphics/Ncurses.cpp

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

LDFLAGS_NCURSES	=	-shared -fPIC -lncurses


##SFML

NAME_SFML	=	lib/arcade_sfml.so

SRC_SFML	=	$(SRC_DIR)Graphics/SFML.cpp

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

LDFLAGS_SFML	=	-shared -fPIC -I/opt/homebrew/Cellar/sfml/2.5.1_2/include -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

##SDL2

NAME_SDL	=	lib/arcade_sdl2.so

SRC_SDL	=	$(SRC_DIR)Graphics/SDL.cpp

OBJ_SDL	=	$(SRC_SDL:.cpp=.o)

LDFLAGS_SDL	=	-shared -fPIC -lSDL2 -lSDL2_ttf

## SNAKE

NAME_SNAKE	=	lib/arcade_snake.so

SRC_SNAKE	=	$(SRC_DIR)Games/Snake.cpp

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

LDFLAGS_SNAKE	=	-shared -fPIC

## NIBBLER

NAME_NIBBLER	=	lib/arcade_nibbler.so

SRC_NIBBLER	=	$(SRC_DIR)Games/Nibbler.cpp

OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)

LDFLAGS_NIBBLER	=	-shared -fPIC

all:	core games graphicals

core:	$(NAME)

games:	$(NAME_SNAKE) $(NAME_NIBBLER)

graphicals:	$(NAME_NCURSES) $(NAME_SFML) $(NAME_SDL)

$(NAME_NCURSES):	$(OBJ_NCURSES)
	$(CXX) $(OBJ_NCURSES) -o $(NAME_NCURSES) $(LDFLAGS_NCURSES)

$(NAME_SFML):	$(OBJ_SFML)
	$(CXX) $(OBJ_SFML) -o $(NAME_SFML) $(LDFLAGS_SFML)

$(NAME_SDL):	$(OBJ_SDL)
	$(CXX) $(OBJ_SDL) -o $(NAME_SDL) $(LDFLAGS_SDL)

$(NAME_SNAKE):	$(OBJ_SNAKE)
	$(CXX) $(OBJ_SNAKE) -o $(NAME_SNAKE) $(LDFLAGS_SNAKE)

$(NAME_NIBBLER):	$(OBJ_NIBBLER)
	$(CXX) $(OBJ_NIBBLER) -o $(NAME_NIBBLER) $(LDFLAGS_NIBBLER)

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ_NCURSES) $(OBJ_NIBBLER) $(OBJ_SNAKE) $(OBJ) $(OBJ_SFML) $(OBJ_SDL)

fclean:		clean
	$(RM) $(NAME_SFML) $(NAME_SDL) $(NAME_SNAKE) $(NAME_NCURSES) $(NAME_NIBBLER) $(NAME)

re:	fclean all

.PHONY:	clean fclean re all
