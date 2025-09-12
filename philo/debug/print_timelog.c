#include "philo.h"

void	print_timelog(long current_time, t_philo *philo, t_data *data)
{
	printf("Current time: %ld\nlast_eaten %ld\ntime2die %d\n", current_time, philo->last_eaten, data->time_to_die);
}
