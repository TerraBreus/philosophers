#include "philo.h"

void	*monitor_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) ptr;
	philo = data->philo1;
	while (true)
	{
		pthread_mutex_lock(philo->lock);
		if (philo->eat_count >= data->total_eat_limit)
		{
			pthread_mutex_lock(data->lock);
			data->should_stop = true;
			pthread_mutex_unlock(data->lock);
			pthread_mutex_unlock(philo->lock);
			break;
		}
		pthread_mutex_unlock(philo->lock);
		philo = philo->philo_r;
	}
	return (NULL);
}

