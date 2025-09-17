#include "philo.h"

void	*ober_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;
	long	current_time;

	data = (t_data *)ptr;
	ft_usleep(data->time_to_die / 2);
	philo = data->philo1;
	while (true)
	{
		pthread_mutex_lock(data->lock);
		if (data->should_stop == true)
		{
			pthread_mutex_unlock(data->lock);
			break;
		}
		pthread_mutex_unlock(data->lock);
		pthread_mutex_lock(philo->lock);
		current_time = get_time();
		if (current_time - philo->last_eaten >= data->time_to_die)
		{
			pthread_mutex_unlock(philo->lock);
			pthread_mutex_lock(data->lock);
			data->should_stop = true;
			pthread_mutex_unlock(data->lock);
			print_log(current_time, philo, DIED);
			break;
		}
		pthread_mutex_unlock(philo->lock);
		philo = philo->philo_r;
	}
	return (NULL);
}
			


