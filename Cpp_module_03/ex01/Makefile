# Variables
NAME = scavtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = Main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling and linking..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Build complete: $(NAME)"

%.o: %.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up object files..."
	rm -f $(OBJS)

fclean: clean
	@echo "Removing binary..."
	rm -f $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
