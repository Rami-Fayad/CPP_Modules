CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98  # Changed to C++98
NAME = Serializer

SRCS = main.cpp Serializer.cpp
HEADERS = Serializer.hpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
