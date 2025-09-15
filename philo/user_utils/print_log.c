#include "philo.h"

void	print_log(long timestamp,t_philo *philo, char *action)
{
	long	time;

	time = timestamp - philo->data->start_time;
	pthread_mutex_lock(philo->data->lock);
	if (philo->data->should_stop == false)
		printf("%lu %i %s", time, philo->ID, action);
	if (*(action + 4) == 'd')
		printf("%lu %i %s", time, philo->ID, action);
	pthread_mutex_unlock(philo->data->lock);
}

//I don't know what else to put here
