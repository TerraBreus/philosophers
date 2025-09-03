#include "philo.h"

void	ft_usleep(long time)
{
	long	start;
	long	time_left;

	start = get_time();
	time_left = time - (get_time() - start);
	while (time_left > time / 4)
	{
		usleep(time_left / 4);
		time_left = time - (get_time() - start);
	}
	while (time_left > 0)
	{
		usleep(1000);		//We must be within 10 ms of actual time_of_death. 
					//Thus 1 ms seems sufficient margin.
		time_left = time - (get_time() - start);
	}
}
