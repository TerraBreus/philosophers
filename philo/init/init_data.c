#include "philo.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*result;

	result = (t_data *)malloc(sizeof(t_data));
	if (result == NULL)
		return (NULL);
	result->n_philo = ft_atoi(argv[1]);
	result->time_to_die = ft_atoi(argv[2]);
	result->time_to_eat = ft_atoi(argv[3]);
	result->time_to_sleep = ft_atoi(argv[4]);
	result->time_to_think = (result->time_to_die - result->time_to_eat - result->time_to_sleep) / 2;
	if (result->time_to_think < 0)
		result->time_to_think = 1;
	if (argc == 6)
		result->total_eat_limit = ft_atoi(argv[5]);
	else 
		result->total_eat_limit = -1;
	return (result);
}
