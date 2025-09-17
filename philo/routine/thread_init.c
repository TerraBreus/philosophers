#include "philo.h"

int	thread_init(t_data *data)
{
	int	i;
	t_philo	*philo_n;

	philo_n = data->philo1;
	i = -1;
	data->start_time = get_time();
	pthread_create(&(data->ober_tid), NULL, ober_routine, (void *) data);
	if (data->total_eat_limit > 0)
		pthread_create(&(data->monitor_tid), NULL, monitor_routine, (void *) data);
	if (data->n_philo == 1)
		pthread_create(&(philo_n->tid), NULL, single_philo, (void *) data);
	else
	{
		while (++i < data->n_philo)
		{
			pthread_create(&(philo_n->tid), NULL, philo_routine,(void *) philo_n);
			philo_n = philo_n->philo_r;
		}
	}
	return (0);
}

