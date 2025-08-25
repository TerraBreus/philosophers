#include "philo.h"

long	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("gettimeofday", NULL);
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec) / (long)1000);
}
