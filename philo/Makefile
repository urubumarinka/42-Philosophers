NAME = philo

CC = cc
CFLAGS = -g -pthread -Wall -Werror -Wextra -I$(INC)

INC = ./inc/

REMOVE = rm -f

SRCS = \
./srcs/main.c \
./srcs/utils.c \
./srcs/parsing.c \
./srcs/data_init.c \
./srcs/safe_handlers.c \
./srcs/dinner_start.c \
./srcs/routine.c \
./srcs/cleanup.c

OBJS = $(SRCS:.c=.o)

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)
	@echo "$(GREEN)Compilation successfully done!!$(RESET)"


$(NAME): $(OBJS)
	@echo "$(CYAN)Linking philo...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Philosophers executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
