#include "philo.h"


static void	destroy_and_free_mutex(t_philo *philo)
{
	if (philo->lock != NULL)
	{
		pthread_mutex_destroy(philo->lock);
		free(philo->lock);
		philo->lock = NULL;
	}
	if (philo->fork_r != NULL)
	{
		pthread_mutex_destroy(philo->fork_r);
		free(philo->fork_r);
		philo->fork_r = NULL;
	}
}

void	cleanup_program(t_data *data)
{
	t_philo	*philo;
	t_philo	*philo_temp;

	if (data->philo1 != NULL)
	{
		philo = data->philo1->philo_r;
		while (philo != data->philo1)
		{
			destroy_and_free_mutex(philo);	
			philo_temp = philo->philo_r;
			free(philo);
			philo = philo_temp;
		}
		destroy_and_free_mutex(data->philo1);
		free(data->philo1);
		data->philo1 = NULL;
	}
	if (data->lock != NULL)
	{
		pthread_mutex_destroy(data->lock);
		free(data->lock);
		data->lock = NULL;
	}
	free(data);
}

