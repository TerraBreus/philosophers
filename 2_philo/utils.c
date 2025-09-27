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
