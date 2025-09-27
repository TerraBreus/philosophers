/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:21:56 by zivanov           #+#    #+#             */
/*   Updated: 2025/09/27 13:52:47 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//xXx I N C L U D E S
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <sys/time.h>

//xXx M A C R O S
#define INSUFFICIENT_ARGUMENTS "\
Insufficient arguments given\n \
Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]*\n\n* If no parameter is given, \
program will run till infinitely (unless a philosopher dies)\n\n"

#define MAX_PHILO "Max amount of philosophers is 200.\n"

#define NON_NUMERICAL_INPUT "No non-numerical characters allowed\n"

#define EAT "is eating.\n"
#define FORK "has taken a fork.\n"
#define DIED "has died.\n"
#define SLEEP "is sleeping.\n"
#define THINK "is thinking.\n"

//xXx S	T R U C T U R E S
typedef struct s_data
{
	long			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				total_eat_limit;
	int				n_philo;
	struct s_philo	*philo1;
	atomic_bool		should_stop;
	pthread_t		ober_tid;
	pthread_mutex_t	*log_mutex;
	pthread_t		monitor_tid;
}	t_data;

typedef struct s_philo
{
	int				nbr;
	pthread_t		tid;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	struct s_philo	*philo_r;
	atomic_long		last_eaten;
	atomic_int		eat_count;
	atomic_bool		eat_limit_reached;
	t_data			*data;
}	t_philo;

//xXx F U N C T I O N S
void	check_input(int argc, char **argv);
void	ft_error(char *str);
int		ft_atoi(char *str);
t_data	*init_structs(int argc, char **argv);
void	cleanup_program(t_data *data, t_philo *philo, int n_philo);
long	get_time(void);
void	print_philo_struct(t_philo *top_philo);
void	print_log(t_philo *philo, pthread_mutex_t *log_mutex, char *action);
void	ft_usleep(long time);
