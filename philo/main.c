/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/06/20 17:23:51 by zivanov        #+#    #+#                */
/*   Updated: 2025/06/20 17:23:53 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo1;

	syntax_checl(argc, argv);
	data = init_data(argv);
	philo1 = init_philo(&data);
	start_philo(data, philo1);
	clean_and_exit(data);
}
