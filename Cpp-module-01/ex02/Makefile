# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable file
EXEC = main

# Source and object files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule to compile the program
all: $(EXEC)

# Linking object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build files
clean:
	rm -f $(OBJS)

# Remove the executable file
fclean: clean
	rm -f $(EXEC)

# Rebuild the program from scratch
re: fclean all

.PHONY: all clean fclean re
