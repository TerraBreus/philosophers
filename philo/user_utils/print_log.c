#include "philo.h"

void	print_log(long timestamp,t_philo *philo, char *action)
{
	long	time;

	time = timestamp - philo->data->start_time;
	printf("%lu %i %s", time, philo->ID, action);
}

//I don't know what else to put here
