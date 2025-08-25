#include "philo.h"

void	close_table(t_philo *philo)
{
	t_philo	*temp;

	temp = philo;
	while (philo->philo_r != NULL)
		philo = philo->philo_r;
	temp->philo_l = philo;
	philo->philo_r = temp;
}
