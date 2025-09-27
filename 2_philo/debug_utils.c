/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:38:31 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/27 13:38:32 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_struct(t_philo *top_philo)
{
	while (top_philo != NULL)
	{
		printf("%i\n", top_philo->nbr);
		printf("fork_l: %p\n", top_philo->fork_l);
		printf("fork_r: %p\n", top_philo->fork_r);
		top_philo = top_philo->philo_r;
	}
}
