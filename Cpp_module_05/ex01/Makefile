# Compiler and flags
CXX        = g++
CXXFLAGS   = -Wall -Wextra -Werror -std=c++98

# Project files
SRC        = Main.cpp Bureaucrat.cpp Form.cpp
OBJ        = $(SRC:.cpp=.o)
TARGET     = form_test

# Colors for output
GREEN      = \033[1;32m
YELLOW     = \033[1;33m
RESET      = \033[0m

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	@echo "$(YELLOW)Linking object files...$(RESET)"
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
	@echo "$(GREEN)Build successful!$(RESET)"

# Compilation
%.o: %.cpp
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and binary
clean:
	@echo "$(YELLOW)Cleaning up object files...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(YELLOW)Removing the executable...$(RESET)"
	@rm -f $(TARGET)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
