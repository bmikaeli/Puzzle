#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbar <mbar@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 12:22:51 by mbar              #+#    #+#              #
#    Updated: 2015/03/09 16:23:03 by mbar             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = n-puzzle

SRC = main.cpp \
		Parser.cpp \
		ManhattanHeuristic.Class.cpp \
		Resolve.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++11

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@g++ -o $(NAME) $(OBJ)

%.o: %.cpp
		g++ $(CFLAGS) -c $^

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
