#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

typedef enum e_action
{
	EATING,
	SLEEPING,
	THINKING,
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
	struct s_philo	*philo1;
}	t_data;

typedef	struct s_philo
{
	int	ID;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct s_philo	*philo_r;
	struct s_philo	*philo_l;
	action		state;
	long		last_eaten;
}	t_philo;

//FUNCTIONS

//	for whenever a philosopher switches state, a message must be printed
//	with the time, the philosopher in question, and the changed state (action).
int	print_log(int timestamp, int philo_n, action action);

//	In case of errors, calls clean_and_exit if data != NULL.
void	ft_error(char *place_of_error, t_data *data);

//	Returns the current time since the epoch in ms using 'gettimeofday'.
long	get_time();


