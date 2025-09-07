#include "philo.h"

int	thread_join(t_data *data)
{
	int		i;
	t_philo		*philo_n;

	philo_n = data->philo1;
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join((philo_n->tid), NULL) != 0)
			return (-1);
		philo_n = philo_n->philo_r;
	}
	return (0);
}
