NAME    = phonebook

SRCS    =   PhoneBook.cpp \
            Contact.cpp \
            main.cpp

OBJS    = $(SRCS:.cpp=.o)

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
GREEN   = \033[1;32m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ Done!$(RESET)"

.cpp.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

