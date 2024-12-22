# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Directories for the sources and object files
SRC_DIR = .
OBJ_DIR = ./obj

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Cat.cpp $(SRC_DIR)/Animal.cpp $(SRC_DIR)/Brain.cpp

# Object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Output executable
TARGET = animals

# Default target to build
all: $(TARGET)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Remove object files only
fclean: clean

# Rebuild everything
re: fclean all

# Ensure we compile in a fresh environment
.PHONY: all clean fclean re
