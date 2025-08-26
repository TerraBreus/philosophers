#include "philo.h"

t_data	*init_all(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (data == NULL)
		return (NULL);
	init_philo(data);	//TODO: check for philo malloc (how?)
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	data = init_all(argc, argv);
	if (data == NULL)
		exit(EXIT_FAILURE);	//TODO
	}
