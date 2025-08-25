#include "philo.h"

int	init_data(int argc, char **argv)
{
	if (syntax_check(argc, argv) == false)
		ft_usage();
	// Initialize (if valid) the data structure.
	data = init_data(argc, argv);
	if (data == NULL)
		exit(EXIT_FAILURE);
	if (data_check(argc, data) == false)
		ft_usage();
}
