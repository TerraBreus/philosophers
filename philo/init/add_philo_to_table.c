#include "philo.h"

int	add_philo_to_table(t_philo *top_philo, int id)
{
	t_philo	*new_philo;

	new_philo = (t_philo *)malloc(sizeof(t_philo));
	if (new_philo == NULL)
		return (-1);

	new_philo->ID = id;
	while (top_philo->philo_r != NULL)
		top_philo = top_philo->philo_r;
	top_philo->philo_r = new_philo;
	new_philo->philo_l = top_philo;
	return (0);
}
