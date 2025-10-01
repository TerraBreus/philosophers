#include "philo.h"

bool	has_died(t_philo *philo)
{
	long	current_time;
	int		time_to_die;
	int		die_check;

	current_time = get_time();
	time_to_die = philo->data->time_to_die;
	die_check = current_time - atomic_load(&philo->last_eaten) - time_to_die;
	
	if (die_check >= 0)
		return (true);
	else
		return (false);
}

void	*death_monitor(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)ptr;
	philo = data->philo1;
	while (atomic_load(&data->should_stop) == false)
	{
		if (has_died(philo) == true)
		{
			atomic_store(&data->should_stop, true);
			print_log(philo, data->log_mutex, DIED);
		}
		philo = philo->philo_r;
		if (philo == NULL)
			philo = data->philo1;
	}
	return (NULL);
}

bool	all_have_eaten(t_philo *philo)
{
	int	eat_limit;
	int	philos_reached_limit;
	int	total_philos;

	eat_limit = philo->data->total_eat_limit;
	total_philos = philo->data->n_philo;
	philos_reached_limit = 0;
	while (philo != NULL)
	{
		if (atomic_load(&philo->eat_count) >= eat_limit)
			philos_reached_limit++;
		philo = philo->philo_r;
	}
	if (philos_reached_limit == total_philos)
		return (true);
	return (false);
}

void	*eat_count_monitor(void	*ptr)
{
	t_data *data;
	t_philo	*philo;

	data = (t_data *)ptr;
	philo = data->philo1;
	while (atomic_load(&data->should_stop) == false)
	{
		if (all_have_eaten(philo) == true)
			atomic_store(&data->should_stop, true);
	}
	return (NULL);
}
