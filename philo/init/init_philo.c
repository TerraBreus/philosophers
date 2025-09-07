#include "philo.h"

int	init_philo(t_data *data)
{
	int	i;
	
	data->philo1 = (t_philo *)calloc(1, sizeof(t_philo));	//TODO am I allowed calloc?
	if (data->philo1 == NULL)
		return (-1);
	data->philo1->ID = 1;
	data->philo1->data = data;
	i = 0;
	while (++i < data->n_philo)
	{
		if (add_philo_to_table(data->philo1, i + 1) != 0)
			return (-1);
	}
	close_table(data->philo1);
	if (init_forks(data) != 0)
		return (-1);
	return (0);
}
