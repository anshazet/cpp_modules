NAME		= Zombie

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main Zombie zombieHorde

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Zombie.hpp

.PHONY: all clean fclean re bonus norm

# Colors (using ANSI escape codes):
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
#	@echo -e "$(GREEN)Executable $(NAME) is ready.$(RESET)"
	@echo "$(GREEN)Executable $(NAME) is ready.$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
#	@echo -e "$(YELLOW)Object files removed.$(RESET)"
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
#	@echo -e "$(YELLOW)Executable $(NAME) removed.$(RESET)"
	@echo "$(YELLOW)Executable $(NAME) removed.$(RESET)"

re: fclean all
