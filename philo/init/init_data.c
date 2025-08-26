#include "philo.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*result;

	if (syntax_check(argc, argv) == false)
	{
		ft_usage();
		return (NULL);
	}
	result = init_data(argc, argv);
	if (result == NULL)
		return (NULL);	
	if (data_check(argc, result) == false)
	{
		ft_usage();
		return (NULL);
	}
	return (result);
}
