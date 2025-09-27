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

void	*philo_even(void *ptr)
{
		t_philo	*philo;
		t_data	*data;

		philo = (t_philo *)ptr;
		data = philo->data;
		while (true)
		{
				//EAT
				pthread_mutex_lock(philo->fork_r);
				print_log(philo, data->log_mutex, FORK);
				pthread_mutex_lock(philo->fork_l);
				atomic_store(&philo->last_eaten, get_time());
				atomic_fetch_add(&philo->eat_count, 1);
				if (atomic_load(&philo->eat_count) == data->total_eat_limit)
						atomic_store(&philo->eat_limit_reached, true);
				print_log(philo, data->log_mutex, EAT);
				ft_usleep(data->time_to_sleep);
				pthread_mutex_unlock(philo->fork_r);
				pthread_mutex_unlock(philo->fork_l);
				if (atomic_load(&data->should_stop) == true)
						break ;
				//SLEEP
				print_log(philo, data->log_mutex, SLEEP);
				ft_usleep(data->time_to_sleep);
				if (atomic_load(&data->should_stop) == true)
						break ;
				//THINK
				print_log(philo, data->log_mutex, THINK);
				ft_usleep(time_to_think);
				if (atomic_load(&data->should_stop) == true)
						break ;
		}
}

void	start_simulation(t_data *data)
{
		data->start_time = get_time();
}
