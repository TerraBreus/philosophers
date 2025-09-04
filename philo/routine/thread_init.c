#include "philo.h"

int	thread_init(t_data *data)
{
	int	i;
	t_philo	*philo_n;

	philo_n = data->philo1;
	i = -1;
	while (++i < data->n_philo)
	{
		if (i % 2)
			ft_msleep(10);	//TODO: dynamic depending on time2die?
		pthread_create(&(philo_n->tid), NULL, philo_routine,(void *) philo_n);

	}
	return (0);
}

