#include "philo.h"

void	print_timelog(long current_time, t_philo *philo, t_data *data)
{
	printf("\n\nPRINTLOG\n");
	printf("Philo: %d\n", philo->ID);
	printf("Current time: %ld\n", current_time);
	printf("last_eaten %ld\n", philo->last_eaten);
	printf("time2die %d\n", data->time_to_die);
	printf("evaluated time%ld\n", current_time - philo->last_eaten);
	printf("\n\n\n");
}
