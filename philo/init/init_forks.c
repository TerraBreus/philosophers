int	init_forks(t_data *data)
{
	t_philo		*philo;
	int		i;

	i = -1;
	philo = data->philo1;
	while (++i < data->n_philo)
	{
		if (philo != NULL)
		{
			philo->fork_r = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
			if (philo->fork_r == NULL)
				return (-1);
			if (pthread_mutex_init(philo->fork_r, NULL) != 0)
				return (-1);
		}
		philo->philo_r->fork_l = philo->fork_r;
		philo = philo->philo_r;
	}
	return (0);
}
