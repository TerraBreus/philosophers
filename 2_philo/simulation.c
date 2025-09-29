/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:33:50 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/27 13:33:58 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_even_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->fork_r);
	print_log(philo, data->log_mutex, FORK);
	pthread_mutex_lock(philo->fork_l);
	atomic_store(&philo->last_eaten, get_time());
	if (atomic_fetch_add(&philo->eat_count, 1) + 1 == data->total_eat_limit)
		atomic_store(&philo->eat_limit_reached, true);
	print_log(philo, data->log_mutex, EAT);
	ft_usleep(data->time_to_sleep);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	*philo_even(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	atomic_store(&philo->last_eaten, data->start_time);
	while (true)
	{
		philo_even_eat(philo, data);
		if (atomic_load(&data->should_stop) == true)
			break ;
		print_log(philo, data->log_mutex, SLEEP);
		ft_usleep(data->time_to_sleep);
		if (atomic_load(&data->should_stop) == true)
			break ;
		print_log(philo, data->log_mutex, THINK);
		ft_usleep(data->time_to_think);
		if (atomic_load(&data->should_stop) == true)
			break ;
	}
	return (NULL);
}

void	philo_uneven_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->fork_l);
	print_log(philo, data->log_mutex, FORK);
	pthread_mutex_lock(philo->fork_r);
	atomic_store(&philo->last_eaten, get_time());
	if (atomic_fetch_add(&philo->eat_count, 1) + 1 == data->total_eat_limit)
		atomic_store(&philo->eat_limit_reached, true);
	print_log(philo, data->log_mutex, EAT);
	ft_usleep(data->time_to_sleep);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	*philo_uneven(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	atomic_store(&philo->last_eaten, data->start_time);
	if (data->time_to_think > 3)
		ft_usleep(data->time_to_think / 2);
	else
		ft_usleep(1);
	while (true)
	{
		philo_uneven_eat(philo, data);
		if (atomic_load(&data->should_stop) == true)
			break ;
		print_log(philo, data->log_mutex, SLEEP);
		ft_usleep(data->time_to_sleep);
		if (atomic_load(&data->should_stop) == true)
			break ;
		print_log(philo, data->log_mutex, THINK);
		ft_usleep(data->time_to_think);
		if (atomic_load(&data->should_stop) == true)
			break ;
	}
	return (NULL);
}

void	start_simulation(t_data *data)
{
	t_philo	*philo;

	philo = data->philo1;
	data->start_time = get_time();
	//TODO Ober and monitor routine
	//if (data->n_philo == 1)
		//TODO single philo.
	while (philo != NULL)
	{
		if (philo->nbr % 2)
		{
			if (pthread_create(&philo->tid, NULL, philo_even, (void *)philo) != 0)
				exit(EXIT_FAILURE);	//TODO; join remaining threads and clean up program.
		}
		else
		{
			if (pthread_create(&philo->tid, NULL, philo_even, (void *)philo) != 0)
				exit(EXIT_FAILURE);	//TODO; join remaining threads and clean up program.
		}
		philo = philo->philo_r;
	}
}
