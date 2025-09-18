#include "philo.h"

void	*single_philo(void *data_ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) data_ptr;
	philo = data->philo1;
	pthread_mutex_lock(philo->lock);
	philo->last_eaten = data->start_time;
	pthread_mutex_unlock(philo->lock);
	pthread_mutex_lock(philo->fork_r);
	print_log(get_time(), philo, FORK);
	ft_usleep(data->time_to_die);
	pthread_mutex_unlock(philo->fork_r);
	return (NULL);
}
