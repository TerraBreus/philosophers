/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:01:52 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/22 11:31:29 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_usage(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(STDERR_FILENO, str, i);
	exit(EXIT_FAILURE);
}
