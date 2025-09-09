#include "philo.h"

int	thread_init(t_data *data)
{
	int	i;
	t_philo	*philo_n;

	philo_n = data->philo1;
	i = -1;
	data->start_time = get_time();
	while (++i < data->n_philo)
	{
		pthread_create(&(philo_n->tid), NULL, philo_routine,(void *) philo_n);
		philo_n = philo_n->philo_r;
	}
	return (0);
}

