CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = RPN

all: $(NAME) no_relink

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
no_relink:
	@echo "                                                     "
	@echo "$(BOLD)$(BLINK)😊 Don't worry, Mr. Jad! 😊$(RESET)"
	@echo "    My Makefile doesn't relink. 🌟"
	@echo "=================================="
	@echo "        ~ Rami Al Fayad ~ "
	@echo "=================================="
	@echo "                                                     "

re: fclean all
