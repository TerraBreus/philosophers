#include "philo.h"

void	*ober_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)ptr;
	philo = data->philo1;
	while (true)
	{
		pthread_mutex_lock(philo->lock);
		if (get_time() - philo->last_eaten>= data->time_to_die)
		{
			pthread_mutex_unlock(philo->lock);
			pthread_mutex_lock(data->lock);
			data->should_stop = true;
			pthread_mutex_unlock(data->lock);
			break;
		}
		pthread_mutex_unlock(philo->lock);
		philo = philo->philo_r;
	}
	return (NULL);
}
			


