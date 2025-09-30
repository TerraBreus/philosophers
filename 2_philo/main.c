/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:47:09 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/27 13:39:26 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_data(t_data *data)
{
	printf("time2die%d\n", data->time_to_die);
	printf("time2eatp%d\n", data->time_to_eat);
	printf("time2sleep%d\n", data->time_to_sleep);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_input(argc, argv);
	data = init_structs(argc, argv);
	print_data(data);
	start_simulation(data);
	end_simulation(data);
	cleanup_program(data, data->philo1, data->n_philo);
	return (0);
}
