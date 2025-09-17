#include "philo.h"

void	*monitor_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;
	int	i;

	i = 0;
	data = (t_data *) ptr;
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
		if (philo->eat_limit_reached == true && philo->already_checked == false)
		{
			philo->already_checked = true;
			i++;
			pthread_mutex_lock(data->lock);
			if (i == data->n_philo)
			{
				data->should_stop = true;
				pthread_mutex_unlock(data->lock);
				pthread_mutex_unlock(philo->lock);
				break;
			}
			pthread_mutex_unlock(data->lock);
		}
		pthread_mutex_unlock(philo->lock);
		philo = philo->philo_r;
	}
	return (NULL);
}

