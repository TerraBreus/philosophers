/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:12:27 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/23 10:40:32 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->log_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (data->log_mutex == NULL)
	{
		free(data);
		return (NULL);
	}
	if (pthread_mutex_init(data->log_mutex, NULL) != 0)
	{
		free(data);
		return (NULL);
	}
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->total_eat_limit = ft_atoi(argv[5]);
	else
		data->total_eat_limit = -1;
	return (data);
}

static t_philo	*create_philo(int id, t_data *data)
{
	t_philo	*result;

	result = (t_philo *)malloc(sizeof(t_philo));
	if (result == NULL)
		return (NULL);
	*result = (t_philo){
		.nbr = id,
		.fork_r = NULL,
		.fork_l = NULL,
		.philo_r = NULL,
		.data = data,
		.eat_limit_reached = ATOMIC_VAR_INIT(false)
		};
	return (result);
}

int	create_forks(t_philo *top_philo)
{
	t_philo	*temp_philo;
	pthread_mutex_t	*temp_fork;

	temp_philo = top_philo;
	while (true)
	{
		temp_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (temp_fork == NULL)
			return (-1);
		if (pthread_mutex_init(temp_fork, NULL) != 0)
			return (-1);
		temp_philo->fork_r = temp_fork;
		if (temp_philo->philo_r == NULL)
			break;
		temp_philo->philo_r->fork_l = temp_fork;
		temp_philo = temp_philo->philo_r;
	}
	top_philo->fork_l = temp_philo->fork_r;
	return (0);
}

static t_philo	*init_philos(int amount_of_philo, t_data *data)
{
	t_philo	*top_philo;
	t_philo	*temp_philo;
	t_philo	*prev_philo;
	int	i;

	top_philo = create_philo(1, data);
	if (top_philo == NULL)
		return (NULL);
	i = 1;
	temp_philo = top_philo;
	while (++i <= amount_of_philo)
	{
		prev_philo = temp_philo;
		temp_philo = create_philo(i, data);
		if (temp_philo == NULL)
		{
			cleanup_program(NULL, top_philo, i);
			return (NULL);
		}
		prev_philo->philo_r = temp_philo;
	}
	if (create_forks(top_philo) == -1)
	{
		cleanup_program(NULL, top_philo, i);
		return (NULL);
	}
	return (top_philo);
}

t_data	*init_structs(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argc, argv);
	if (data == NULL)
		ft_error("malloc failure in data_struct\n");
	data->philo1 = init_philos(data->n_philo, data);
	if (data->philo1 == NULL)
	{
		cleanup_program(data, NULL, -1);
		ft_error("mutex or malloc failure in philo_struct\n");
	}
	atomic_store(&(data->should_stop), false);
	return (data);
}
