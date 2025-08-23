#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

#define USAGE "Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]*\n\n* If no parameter is given, program will run till infinitely (unless a philosopher dies)\n\nMax amount of philosophers is 200.\n"

typedef enum e_action
{
	THINKING,
	EATING,
	SLEEPING,
	FORK1,
	FORK2,
	DEAD
}	action;

typedef struct s_data
{
	long	start_time;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	total_eat_limit;
	int	n_philo;
	struct s_philo	*philo1;
}	t_data;

typedef	struct s_philo
{
	int	ID;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct s_philo	*philo_r;
	struct s_philo	*philo_l;
	long			last_eaten;
	action		state;
}	t_philo;

//FUNCTIONS

//	for whenever a philosopher switches state, a message must be printed
//	with the time, the philosopher in question, and the changed state (action).
int	print_log(int timestamp, int philo_n, action action);

//	In case of errors, calls clean_and_exit if data != NULL.
void	ft_error(char *place_of_error, t_data *data);


int	init_philo(t_data *data);
int	init_forks(t_data *data);
void	close_table(t_philo *philo);
int	add_philo_to_table(t_philo *top_philo, int id);
bool	data_check(int argc, t_data *data);
t_data	*init_data(int argc, char **argv);
int	ft_atoi(const char *nptr);
static int	ft_calc_int(const char *str, size_t length, int conv_int);
static size_t	ft_get_length(const char *input);
int	ft_usage(void);
bool	syntax_check(int argc, char **argv);
void	*philo_routine(void *philo);
void	ft_error(char *place_of_error, t_data *data);
void	clean_and_exit(t_data *data);


// 			-- D E B U G G I N G --
// 			functions for debugging while program is in development.

void	print_philo(t_data *data);
//	Prints the memory adresses of the philosopher and 
//	(the adresses of) their corresponding forks.

// 			-- I N I T I A L I Z A T I O N --
// 			mallocs, syntax checks,
// 			creation of circular loops etc.

// 			-- U S E R -- U T I L S --
// 			functions that give the user information about the program.

void	ft_error(char *place_of_error, t_data *data);

// -- P R O G R A M M E R -- U T I L S --
// util functions that make the life of a programmer liveable.

//	Returns the current time since the epoch in ms using 'gettimeofday'.
long	get_time();

// PHILOSOPHER LIFESTYLE
