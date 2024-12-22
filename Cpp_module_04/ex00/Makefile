# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target name
TARGET = polymorphism

# Source files
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)
	@echo "Compilation successful. Executable: $(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	rm -f $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	rm -f $(TARGET)
	@echo "Executable $(TARGET) removed."

re: fclean all
	@echo "Rebuilt the project."

.PHONY: all clean fclean re
