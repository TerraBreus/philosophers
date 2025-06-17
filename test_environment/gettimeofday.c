#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	long	u_epoch;

	struct timeval	tv;

	gettimeofday(&tv, NULL);
	
	u_epoch = tv.tv_usec;
}
