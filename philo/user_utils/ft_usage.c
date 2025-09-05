#include "philo.h"

int	ft_get_len(char *str)	//TODO put in own file.
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_usage(void)
{
	write(STDERR_FILENO, GEN_USAGE, ft_get_len(GEN_USAGE));
	return (-1);
}
