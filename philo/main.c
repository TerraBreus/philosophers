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

t_data	*init_all(int argc, char **argv)
{
	t_data	*data;

	if (syntax_check(argc, argv) == false)
		ft_usage();	//TODO
	data = init_data(argc, argv);
	if (data_check(argc, data) == false)
		ft_usage();	//TODO
	init_philo(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	data = init_all(argc, argv);
	if (data == NULL)
		exit(EXIT_FAILURE);	//TODO
	}
