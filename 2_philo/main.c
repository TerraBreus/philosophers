/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:47:09 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/27 13:39:26 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philo(void *data_ptr)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) data_ptr;
	philo = data->philo1;
	atomic_store(&philo->last_eaten, data->start_time);
	pthread_mutex_lock(philo->fork_r);
	print_log(philo, data->log_mutex, FORK);
	ft_usleep(data->time_to_die);
	pthread_mutex_unlock(philo->fork_r);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_input(argc, argv);
	data = init_structs(argc, argv);
	start_simulation(data);
	end_simulation(data);
	cleanup_program(data, data->philo1, data->n_philo);
	return (0);
}
