#include "philo.h"

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
