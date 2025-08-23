bool	data_check(int argc, t_data *data)
{
	if (data->time_to_die < 0)
		return (false);
	if (data->time_to_eat < 0)
		return (false);
	if (data->time_to_sleep < 0)
		return (false);
	if (data->n_philo < 1)
		return (false);
	if (argc == 6)
	{
		if (data->total_eat_limit < 0)
			return (false);
	}
	return (true);
}
