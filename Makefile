NAME := philo
CC := cc
CFLAGS := -Wall -Werror -Wextra
DEBUG := -g
SANITIZE := -fsanitize=adress

SRC_INIT := \
	add_philo_to_table.c	\
	close_table.c		\
	data_check.c		\
	init_data.c		\
	init_forks.c		\
	init_philo.c		\
	syntax_check.c

SRC_USER_UTILS = \
	ft_error.c		\
	ft_usage.c		\
	print_log.c

SRC_PROG_UTILS = \
	clean_and_exit.c	\
	ft_atoi.c		\
	get_time.c

SRC_DEBUG = \
	print_philo.c

SRC := \
	$(addprefix init, $(SRC_INIT)) \
	$(addprefix user_utils, $(SRC_USER_UTILS)) \
	$(addprefix prog_utils, $(SRC_PROG_UTILS))

OBJ = $(addprefix obj, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

