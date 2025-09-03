//xXx I N C L U D E S
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

//xXx M A C R O S
#define GEN_USAGE "Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]*\n\nAll times are in milliseconds. \n* If no parameter is given, program will run till infinitely (unless a philosopher dies)\n\n"
#define USAGE_MAX "Max amount of philosophers is 200.\n"
#define USAGE_INPUT "No non-numerical characters allowed\n"

#define EAT "is eating.\n"
#define FORK "has taken a fork.\n"
#define DIED "has died.\n"
#define SLEEP "is sleeping.\n"
#define THINK "is thinking.\n"

//xXx S T R U C T U R E S
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
	long	time_of_death;
	int	dead_philo;
	struct s_philo	*philo1;
}	t_data;

typedef	struct s_philo
{
	int	ID;
	pthread_t	tid;
	pthread_mutex_t	*lock;	//TODO if any variable needs checking/changing we can use the lock in order to
				//avoid problems with data races (checking/changing at the same time)
				//fe: state needs to be locked if checked/changed. Same goes for last_eaten
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct s_philo	*philo_r;
	struct s_philo	*philo_l;
	long			last_eaten;
	long		eat_count;
	action		state;
}	t_philo;

//xXx F U N C T I O N S -

// 			-- D E B U G G I N G --
// 			functions for debugging while program is in development.

void	print_philo(t_data *data);
//	Prints the memory adresses of the philosopher and 
//	(the adresses of) their corresponding forks.

// 			-- I N I T I A L I Z A T I O N --
// 			mallocs, syntax checks,
// 			creation of circular loops etc.

int	init_philo(t_data *data);
int	init_forks(t_data *data);
void	close_table(t_philo *philo);
int	add_philo_to_table(t_philo *top_philo, int id);
bool	data_check(int argc, t_data *data);
t_data	*init_data(int argc, char **argv);
bool	syntax_check(int argc, char **argv);

// 			-- U S E R -- U T I L S --
// 			functions that give the user information about the program.

void	ft_error(char *place_of_error, t_data *data);	//TODO
//	In case of errors, calls clean_and_exit if data != NULL.

int	ft_usage(void);	//TODO: implement macro for different usage errors
//	prints message to the user on how to
//	(correctly) start the program.

int	print_log(int timestamp, int philo_n, action action);	//TODO
//	for whenever a philosopher switches state, a message must be printed
//	with the time, the philosopher in question, and the changed state (action).


// 			-- P R O G R A M M E R -- U T I L S --
//			util functions that make the life of a programmer liveable.

int	ft_get_len(char *str);
//	simple string iterator returning length of string in int.

long	get_time();
//	Returns the current time since the epoch in ms using 'gettimeofday'.

int	ft_atoi(const char *nptr);
//	Converts a string of numbers into an actual integer.

void	clean_and_exit(t_data *data);	//TODO

void	ft_usleep(long time);
//	sleeps for (at least) 'time' amount of microseconds.

// 			-- P H I L O S O P H E R -- L I F E S T Y L E --

void	*philo_routine(void *philo);	//TODO
