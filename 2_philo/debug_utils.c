#include "philo.h"

void	print_philo_struct(t_philo *top_philo)
{
	while (top_philo != NULL)
	{
		printf("%i\n", top_philo->nbr);
		printf("fork_l: %p\n", top_philo->fork_l);
		printf("fork_r: %p\n", top_philo->fork_r);
		top_philo = top_philo->philo_r;
	}
}
