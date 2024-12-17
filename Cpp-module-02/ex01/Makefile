# Compiler and Flags
CXX         = g++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# Files and Directories
SRC_DIR     = .
OBJ_DIR     = obj
SRC_FILES   = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp
OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET      = fixed_point

# Create object directory if it doesn't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

# Rebuild everything
re: fclean $(TARGET)

# Utility target to run the program
run: $(TARGET)
	./$(TARGET)

# Phony Targets
.PHONY: all clean fclean re run
