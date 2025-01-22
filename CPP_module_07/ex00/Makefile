# Makefile for exercise 00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = whatever

all: $(NAME)

$(NAME): main.cpp whatever.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:
	# No object files in this exercise

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
