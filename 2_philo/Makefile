NAME := philo
CC := cc
CFLAGS := -Wall -Werror -Wextra -Iinc
DEBUG := -g
SANITIZE := -fsanitize=address

SRC := \
	main.c \
	init_structs.c \
	utils.c \
	check_syntax.c \
	debug_utils.c \
	simulation.c \
	death_monitor.c

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

obj/%.o : %.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

debug : fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG) $(SANITIZE)" all 
