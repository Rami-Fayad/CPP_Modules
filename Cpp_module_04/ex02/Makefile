NAME = abstract_animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp AAnimal.cpp Brain.cpp Dog.cpp Cat.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Compiled $(NAME)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	rm -f $(OBJ_FILES)
	@echo "Cleaned object files"

fclean: clean
	rm -f $(NAME)
	@echo "Removed $(NAME)"

re: fclean all
