NAME = philo

CC = cc
CFLAGS = -g -pthread -Wall -Werror -Wextra

REMOVE = rm -f

SRCS = \
./main.c \
./utils.c \
./parsing.c \

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
	@echo "$(GREEN)push_swap executable created successfully!$(RESET)"

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(REMOVE) $(OBJS)
	$(MAKE) -C clean

fclean: clean
	@echo "$(YELLOW)Removing executables...$(RESET)"
	$(REMOVE) $(NAME)
	$(MAKE) -C fclean

re: fclean all

.PHONY: all clean fclean re
