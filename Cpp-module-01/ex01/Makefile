# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable name
NAME = zombieHorde

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to build the executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
