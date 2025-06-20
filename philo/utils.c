#include "philo.h"

int	print_log(int timestamp, int philo_n, action action)
{
	/*
	 * Print either of the following messages
	 *
	 * timestamp_in_ms X has taken a fork
	 * timestamp_in_ms X is eating
	 * timestamp_in_ms X is sleeping
	 * timestamp_in_ms X is thinking
	 * timestamp_in_ms X died
	*/
	return (0);
}

void	ft_error(char *place_of_error, t_data *data)
{
	perror(place_of_error);
	if (data != NULL)
		clean_and_exit(data);
}

long	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("gettimeofday", NULL);
	return ((tv.tv_sec * (long)1000) + (tv.tv_sec) / (long)1000);
}
