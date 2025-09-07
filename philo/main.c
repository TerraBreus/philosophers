#include "philo.h"

t_data	*init_all(int argc, char **argv)
{
	t_data	*data;

	if (syntax_check(argc, argv) == false)
	{
		ft_usage();
		return (NULL);
	}
	data = init_data(argc, argv);
	if (data == NULL)
		return (NULL);
	if (data_check(argc, data) == false)
	{
		ft_usage();
		return (NULL);
	}
	if (init_philo(data) != 0)	//TODO: check for philo malloc (how?)
		return (NULL);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	data = init_all(argc, argv);
	if (data == NULL)
		exit(EXIT_FAILURE);	//TODO
	print_philo(data);
	thread_init(data);		//TODO could fail so need save failures.
	thread_join(data);
}
