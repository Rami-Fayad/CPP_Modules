NAME = btc
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME) no_relink

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

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
