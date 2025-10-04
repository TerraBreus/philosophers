/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:01:52 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/23 10:14:35 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_program(t_data *data, t_philo *philo, int n_philo)
{
	t_philo	*temp;
	int		i;

	if (philo != NULL)
	{
		i = -1;
		temp = philo;
		while (++i < n_philo && temp != NULL)
		{
			if (temp->fork_r != NULL)
			{
				pthread_mutex_destroy(temp->fork_r);
				free(temp->fork_r);
			}
			temp = temp->philo_r;
			free(philo);
			philo = temp;
		}
	}
	if (data != NULL)
	{
		pthread_mutex_destroy(data->log_mutex);
		free(data->log_mutex);
		free(data);
	}
}

void	ft_usleep(long time)
{
	long	start;
	long	time_left;

	start = get_time();
	time_left = time - (get_time() - start);
	while (time_left > time / 4)
	{
		usleep(time_left / 4);
		time_left = time - (get_time() - start);
	}
	while (time_left > 0)
	{
		usleep(500);
		time_left = time - (get_time() - start);
	}
}

void	print_log(t_philo *philo, pthread_mutex_t *log_mutex, char *action)
{
	long	time;

	pthread_mutex_lock(log_mutex);
	time = get_time() - philo->data->start_time;
	if (atomic_load(&philo->data->should_stop) == false)
		printf("%lu %i %s", time, philo->nbr, action);
	if (*(action + 4) == 'd')
		printf("%lu %i %s", time, philo->nbr, action);
	pthread_mutex_unlock(log_mutex);
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		result *= 10;
		result += str[i] - '0';
	}
	return (result);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(STDERR_FILENO, str, i);
	exit(EXIT_FAILURE);
}

long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_error("gettimeofday");
	return ((tv.tv_sec * (long)1000) + (tv.tv_usec) / (long)1000);
}
