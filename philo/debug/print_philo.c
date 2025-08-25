#include "philo.h"

void	print_philo(t_data *data)
{
	t_philo		*philo;
	int		i;

	i = -1;
	philo = data->philo1;
	while (++i < data->n_philo)
	{
		if (philo != NULL)
		{
			printf("Philo: %p\n", philo);
			printf("fork_r: %p\nfork_l: %p\n\n", philo->fork_r, philo->fork_l);
			philo = philo->philo_r;
		}
	}
}

