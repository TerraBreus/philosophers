/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:59:58 by zivanov           #+#    #+#             */
/*   Updated: 2025/10/04 15:14:37 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printlog_and_sleep(t_data *data, t_philo *philo, char *action)
{
	print_log(philo, data->log_mutex, action);
	if (*(action + 3) == 's')
		ft_usleep(data->time_to_sleep);
	else if (*(action + 3) == 't')
		ft_usleep(data->time_to_think);
	else if (*(action + 3) == 'e')
		ft_usleep(data->time_to_eat);
}
void	philo_even_eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->fork_r);
	print_log(philo, data->log_mutex, FORK);
	pthread_mutex_lock(philo->fork_l);
	atomic_store(&philo->last_eaten, get_time());
	if (atomic_fetch_add(&philo->eat_count, 1) + 1 == data->total_eat_limit)
		atomic_store(&philo->eat_limit_reached, true);
	printlog_and_sleep(data, philo, EAT);
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
		printlog_and_sleep(data, philo, SLEEP);
		if (atomic_load(&data->should_stop) == true)
			break ;
		printlog_and_sleep(data, philo, THINK);
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
	printlog_and_sleep(data, philo, EAT);
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
		ft_usleep(2);
	while (true)
	{
		philo_uneven_eat(philo, data);
		if (atomic_load(&data->should_stop) == true)
			break ;
		printlog_and_sleep(data, philo, SLEEP);
		if (atomic_load(&data->should_stop) == true)
			break ;
		printlog_and_sleep(data, philo, THINK);
		if (atomic_load(&data->should_stop) == true)
			break ;
	}
	return (NULL);
}
