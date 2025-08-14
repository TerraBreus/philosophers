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
}	t_philo;

int	print_log(int timestamp, int philo_n, action action)
{
	/*
	 * Print either of the following messages
	 *
	 * timestamp_in_ms X has taken a fork
	 * timestamp_in_ms X is eating
	 * timestamp_in_ms X is sleeping
	 * timestamp_in_ms X is thinking
	 * timestamp_in_ms X died
	*/
	return (0);
}

void	clean_and_exit(t_data *data)
{
	//clean up all philosophers, then clean up data.
}

void	ft_error(char *place_of_error, t_data *data)
{
	perror(place_of_error);
	if (data != NULL)
		clean_and_exit(data);
}

// Function returns time in miliseconds
// 1 second is a 1000 miliseconds.
// (tv.tv_sec * (long)1000) -> Seconds to miliseconds
// 1 micro second is 0.001 milisecond.
// (tv.tv_usec) / (long)1000) -> microseconds to miliseconds.

long	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("gettimeofday", NULL);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec) / (long)1000);
}
	
void	*philo_routine(void *philo)
{

	return (philo);
}

bool	syntax_check(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (false);

	i = 1;
	while (argv[i] != NULL)
	{
		while (*argv[i] != '\0')
		{
			if (*argv[i] < '0' || *argv[i] > '9')
				return (false);
			argv[i]++;
		}
		i++;
	}
	return (true);
}

void	ft_usage(void)
{
	write(STDERR_FILENO, "Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]*\n\n* If no parameter is given, program will run till infinitely (unless a philosopher dies)\n\nMax amount of philosophers is 200.\n", 244);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (syntax_check(argc, argv) == false)
		ft_usage();

	// Initialize (if valid) the data structure.
//	data = init_data(data);
	// initialize the forks and philosopher structures.
//	init_philo(data);
}
