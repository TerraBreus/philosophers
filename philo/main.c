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

	if	(init_data(argc, argv, &data) != 0)
		exit(EXIT_FAILURE);
	if (init_philo(data) != NULL)
		exit(EXIT_FAILURE);
	
}
