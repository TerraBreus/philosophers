/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:33:50 by zivanov           #+#    #+#             */
/*   Updated: 2025/10/04 15:01:01 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_data *data)
{
	int		i;
	t_philo	*philo;

	pthread_join(data->ober_tid, NULL);
	if (data->total_eat_limit > 0)
		pthread_join(data->monitor_tid, NULL);
	philo = data->philo1;
	i = 0;
	//TODO: Do something here if threads_created != n_philos
	//aka this means something went wrong with thread creation
	//and we have to detach or force the threads to exit.
	while (++i <= data->threads_created)
	{
		pthread_join(philo->tid, NULL);
		philo = philo->philo_r;
	}
}

void	start_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		ober_and_monitor;

	i = 0;
	philo = data->philo1;
	if (data->n_philo == 1)
	{
		if (pthread_create(&philo->tid, NULL, single_philo, (void *)data) != 0)
			return ;
		data->threads_created++;
	}
	else
	{
		while (++i <= data->n_philo)
		{
			if (philo->nbr % 2)
			{
				if (pthread_create(&philo->tid, NULL, philo_uneven, (void *)philo) != 0)
					return ;
			}
			else
			{
				if (pthread_create(&philo->tid, NULL, philo_even, (void *)philo) != 0)
					return ;
			}
			philo = philo->philo_r;
			data->threads_created++;
		}
	}
	if (pthread_create(&data->ober_tid, NULL, death_monitor, (void *)data) != 0)
		return ;
	ober_and_monitor = 1;
	if (data->total_eat_limit > 0)
	{
		if (pthread_create(&data->monitor_tid, NULL, eat_count_monitor, (void *)data) != 0)
			return ;
		ober_and_monitor = 2;
	}
	while (atomic_load(&data->n_ready) != data->n_philo + ober_and_monitor);
	data->start_time = get_time();
	atomic_store(&data->simulation_ready, true);	
	//TODO Note: all created threads will hang if a thread creation fails.
	//Thus we also need to make sure all threads join correctly when an error occurs
}
