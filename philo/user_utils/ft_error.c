#include "philo.h"

void	ft_error(char *place_of_error, t_data *data)
{
	write(STDERR_FILENO, place_of_error, ft_get_len(place_of_error));
	//TODO: clean and exit
	if (data != NULL)
		data = NULL;
}

