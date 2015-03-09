NAME = npuzzle

CC = clang++
#CC = /usr/local/Cellar/gcc/4.9.2_1/bin/g++-4.9
#CC = g++

SRC = main.cpp Game.Class.cpp ManhattanHeuristic.Class.cpp EuclidHeuristic.Class.cpp

OBJ = $(SRC:.cpp=.o)

FLAG = -Wall -Werror -Wextra -std=c++11

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAG) -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all