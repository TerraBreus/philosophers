/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:51:40 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/23 09:17:46 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_only_numerical(char *str)
{
	if (str == NULL)
		return (false);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	check_input(int argc, char **argv)
{
	int	max_philo;

	argv++;
	if (argc > 6 || argc < 5)
		ft_error(INSUFFICIENT_ARGUMENTS);
	while (*argv != NULL)
	{
		if (is_only_numerical(*argv) == false)
			ft_error(NON_NUMERICAL_INPUT);
		argv++;
	}
	if (argc > 6 || argc < 5)
		ft_error(INSUFFICIENT_ARGUMENTS);
	max_philo = ft_atoi(argv[1]);
	if (max_philo > 200)
		ft_error(MAX_PHILO);
}
