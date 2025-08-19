#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

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
	int	j;

	if (argc < 5 || argc > 6)
		return (false);

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	ft_usage(void)
{
	write(STDERR_FILENO, "Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]*\n\n* If no parameter is given, program will run till infinitely (unless a philosopher dies)\n\nMax amount of philosophers is 200.\n", 240);
	exit(EXIT_FAILURE);
	//technically I want the clean_and_exit function so I don't have leaks.
}

static size_t	ft_get_length(const char *input)
{
	size_t	length;

	length = 0;
	if (*input >= '0' && *input <= '9')
	{
		length = 1;
		input++;
	}
	while (*input >= '0' && *input <= '9')
	{
		input++;
		length *= 10;
	}
	return (length);
}

static int	ft_calc_int(const char *str, size_t length, int conv_int)
{
	while (length)
	{
		conv_int += (*str - '0') * length;
		length /= 10;
		str++;
	}
	return (conv_int);
}

int	ft_atoi(const char *nptr)
{
	int			conv_int;
	int			is_minus;

	is_minus = 1;
	conv_int = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_minus *= -1;
		nptr++;
	}
	while (*nptr == '0')
		nptr++;
	conv_int = ft_calc_int(nptr, ft_get_length(nptr), conv_int);
	conv_int *= is_minus;
	return (conv_int);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*result;

	result = (t_data *)malloc(sizeof(t_data));
	if (result == NULL)
		return (NULL);
	result->start_time = get_time();
	result->n_philo = ft_atoi(argv[1]);
	result->time_to_die = ft_atoi(argv[2]);
	result->time_to_eat = ft_atoi(argv[3]);
	result->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		result->total_eat_limit = ft_atoi(argv[5]);
	else 
		result->total_eat_limit = -1;
	return (result);
}

bool	data_check(int argc, t_data *data)
{
	if (data->time_to_die < 0)
		return (false);
	if (data->time_to_eat < 0)
		return (false);
	if (data->time_to_sleep < 0)
		return (false);
	if (data->n_philo < 1)
		return (false);
	if (argc == 6)
	{
		if (data->total_eat_limit < 0)
			return (false);
	}
	return (true);
}

int	add_philo_to_table(t_philo *top_philo, int id)
{
	t_philo	*new_philo;

	new_philo = (t_philo *)malloc(sizeof(t_philo));
	if (new_philo == NULL)
		return (-1);

	new_philo->ID = id;
	while (top_philo->philo_r != NULL)
		top_philo = top_philo->philo_r;
	top_philo->philo_r = new_philo;
	new_philo->philo_l = top_philo;
	return (0);
}

void	close_table(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (philo->philo_r != NULL)
		philo = philo->philo_r;
	temp->philo_l = philo;
	philo->philo_r = temp;
}

int	init_forks(t_data *data)
{
	t_philo		*philo;
	int		i;

	i = -1;
	philo = data->philo1;
	while (++i < data->n_philo)
	{
		if (philo != NULL)
		{
			if (pthread_mutex_init(philo->fork_r, NULL) == 0)
				return (-1);
		}
		philo->philo_r->fork_l = philo->fork_r;
		philo = philo->philo_r;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;
	
	data->philo1 = (t_philo *)malloc(sizeof(t_philo));
	if (data->philo1 == NULL)
		return (-1);
	data->philo1->ID = 1;
	i = 0;
	while (++i < data->n_philo)
	{
		if (add_philo_to_table(data->philo1, i + 1) != 0)
			return (-1);
	}
	close_table(data->philo1);
	//Create forks and Assign values to the philosophers.
	if (init_forks(data) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (syntax_check(argc, argv) == false)
		ft_usage();

	// Initialize (if valid) the data structure.
	data = init_data(argc, argv);
	if (data == NULL)
		exit(EXIT_FAILURE);
	if (data_check(argc, data) == false)
		ft_usage();
	// initialize the forks and philosopher structures.
	init_philo(data);
}
