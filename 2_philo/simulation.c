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
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	*philo_even(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	atomic_fetch_add(&data->n_ready, 1);
	while (!atomic_load(&data->simulation_ready))
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
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	*philo_uneven(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	data = philo->data;
	atomic_fetch_add(&data->n_ready, 1);
	while (!atomic_load(&data->simulation_ready))
	atomic_store(&philo->last_eaten, data->start_time);
	if (data->time_to_think > 3)
		ft_usleep(data->time_to_think / 2);
	else
		ft_usleep(4);
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

	i = 0;
	philo = data->philo1;
	if (data->n_philo == 1)
	{
		if (pthread_create(&philo->tid, NULL, single_philo, (void *)data) != 0)
			return ;
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
	while (atomic_load(&data->n_ready) != data->n_philo);
	data->start_time = get_time();
	atomic_store(&data->simulation_ready, true);	
	if (pthread_create(&data->ober_tid, NULL, death_monitor, (void *)data) != 0)
		return ;
	if (data->total_eat_limit > 0)
	{
		if (pthread_create(&data->monitor_tid, NULL, eat_count_monitor, (void *)data) != 0)
			return ;
	}
	//TODO Note: all created threads will hang if a thread creation fails.
	//Thus we also need to make sure all threads join correctly when an error occurs
}
