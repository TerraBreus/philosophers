/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:47:09 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/23 09:35:31 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	check_input(argc, argv);
	data = init_structs(argc, argv);
	start_simulation(data);
	end_simulation(data);
	cleanup_program(data);
	return (0);
}
