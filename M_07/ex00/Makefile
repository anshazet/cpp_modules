NAME		= Whatever

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

.PHONY: all clean fclean re

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) is ready.$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@echo "$(YELLOW)Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)Executable $(NAME) removed.$(RESET)"

re: fclean all