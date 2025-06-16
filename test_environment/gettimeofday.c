#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	long	hour;

	struct timeval	tv;

	gettimeofday(&tv, NULL);
	
	hour = tv.tv_sec/3600;
	printf("%ld\n", hour);
}
